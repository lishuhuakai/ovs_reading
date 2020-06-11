/*
 * Copyright (c) 2007-2015 Nicira, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 */

#ifndef FLOW_H
#define FLOW_H 1

#include <linux/cache.h>
#include <linux/kernel.h>
#include <linux/netlink.h>
#include <linux/openvswitch.h>
#include <linux/spinlock.h>
#include <linux/types.h>
#include <linux/rcupdate.h>
#include <linux/if_ether.h>
#include <linux/in6.h>
#include <linux/jiffies.h>
#include <linux/time.h>
#include <linux/flex_array.h>
#include <net/inet_ecn.h>
#include <net/ip_tunnels.h>
#include <net/dst_metadata.h>

struct sk_buff;

/* Store options at the end of the array if they are less than the
 * maximum size. This allows us to get the benefits of variable length
 * matching for small options.
 */
#define TUN_METADATA_OFFSET(opt_len) \
	(FIELD_SIZEOF(struct sw_flow_key, tun_opts) - opt_len)
#define TUN_METADATA_OPTS(flow_key, opt_len) \
	((void *)((flow_key)->tun_opts + TUN_METADATA_OFFSET(opt_len)))

struct ovs_tunnel_info {
	struct metadata_dst     *tun_dst;
};

#define OVS_SW_FLOW_KEY_METADATA_SIZE			\
	(offsetof(struct sw_flow_key, recirc_id) +	\
	FIELD_SIZEOF(struct sw_flow_key, recirc_id))

/*
 * sw_flow_key是整个openvswitch中最为重要的结构体
 * 它主要存储数据包中协议相关的信息,这是后期进行流表匹配最为关键的结构
 */
struct sw_flow_key {
	u8 tun_opts[255];
	u8 tun_opts_len;
	struct ip_tunnel_key tun_key;  /* Encapsulating tunnel key. */
	struct {
        /* 包的优先级 */
		u32	priority;	/* Packet QoS priority. */
        /* 包的mask值 */
		u32	skb_mark;	/* SKB mark. */
        /* 包进入的端口号 */
		u16	in_port;	/* Input switch port (or DP_MAX_PORTS). */
	} __packed phy; /* Safe when right after 'tun_key'. */
	u32 ovs_flow_hash;		/* Datapath computed hash value.  */
	u32 recirc_id;			/* Recirculation ID.  */
    /* 以太网头部信息 */
	struct {
	    /* 源mac */
		u8     src[ETH_ALEN];
        /* 目的mac */
		u8     dst[ETH_ALEN];
		__be16 tci;		/* 0 if no VLAN, VLAN_TAG_PRESENT set otherwise. */
        /* 包的类型: ip包还是arp包 */
		__be16 type;		/* Ethernet frame type. */
	} eth;
	union {
		struct {
			__be32 top_lse;	/* top label stack entry */
		} mpls;
		struct {
            /* 协议类型, tcp--6 udp--17 */
			u8     proto;	/* IP protocol or lower 8 bits of ARP opcode. */
            /* 服务类型 */
			u8     tos;	    /* IP ToS. */
            /* 生存时间 */
			u8     ttl;	    /* IP TTL/hop limit. */
			u8     frag;	/* One of OVS_FRAG_TYPE_*. */
		} ip;
	};
	struct {
		__be16 src;		/* TCP/UDP/SCTP source port. */
		__be16 dst;		/* TCP/UDP/SCTP destination port. */
		__be16 flags;		/* TCP flags. */
	} tp;
	union {
		struct {
			struct {
				__be32 src;	/* IP source address. */
				__be32 dst;	/* IP destination address. */
			} addr;
			struct {
				u8 sha[ETH_ALEN];	/* ARP source hardware address. */
				u8 tha[ETH_ALEN];	/* ARP target hardware address. */
			} arp;
		} ipv4;
		struct {
			struct {
				struct in6_addr src;	/* IPv6 source address. */
				struct in6_addr dst;	/* IPv6 destination address. */
			} addr;
			__be32 label;			/* IPv6 flow label. */
			struct {
				struct in6_addr target;	/* ND target address. */
				u8 sll[ETH_ALEN];	/* ND source link layer address. */
				u8 tll[ETH_ALEN];	/* ND target link layer address. */
			} nd;
		} ipv6;
	};
	struct {
		/* Connection tracking fields. */
		u16 zone;
		u32 mark;
		u8 state;
		struct ovs_key_ct_labels labels;
	} ct;

} __aligned(BITS_PER_LONG/8); /* Ensure that we can do comparisons as longs. */

struct sw_flow_key_range {
	unsigned short int start;
	unsigned short int end;
};

struct sw_flow_mask {
	int ref_count;
	struct rcu_head rcu;
	struct sw_flow_key_range range; /* 操作范围结构体 */
	struct sw_flow_key key;
};

struct sw_flow_match {
	struct sw_flow_key *key;
	struct sw_flow_key_range range;
	struct sw_flow_mask *mask;
};

#define MAX_UFID_LENGTH 16 /* 128 bits */

struct sw_flow_id {
	u32 ufid_len;
	union {
		u32 ufid[MAX_UFID_LENGTH / 4];
		struct sw_flow_key *unmasked_key;
	};
};

struct sw_flow_actions {
	struct rcu_head rcu;
	size_t orig_len;	/* From flow_cmd_new netlink actions size */
	u32 actions_len;
	struct nlattr actions[];
};

struct flow_stats {
	u64 packet_count;		/* Number of packets matched. */
	u64 byte_count;			/* Number of bytes matched. */
	unsigned long used;		/* Last used time (in jiffies). */
	spinlock_t lock;		/* Lock for atomic stats update. */
	__be16 tcp_flags;		/* Union of seen TCP flags. */
};

/* 流表项 */
struct sw_flow {
	struct rcu_head rcu; /* rcu保护机制 */
	struct {
		struct hlist_node node[2];
		u32 hash; /* hash值 */
	} flow_table, ufid_table;
	int stats_last_writer;		/* NUMA-node id of the last writer on
					 * 'stats[0]'.
					 */
	struct sw_flow_key key; /* 流表中的key */
	struct sw_flow_id id;
	struct sw_flow_mask *mask; /* 要匹配的mask结构体 */
	struct sw_flow_actions __rcu *sf_acts; /* 需要匹配的动作 */
	struct flow_stats __rcu *stats[]; /* One for each NUMA node.  First one
					   * is allocated at flow creation time,
					   * the rest are allocated on demand
					   * while holding the 'stats[0].lock'.
					   */
};

struct arp_eth_header {
	__be16      ar_hrd;	/* format of hardware address   */
	__be16      ar_pro;	/* format of protocol address   */
	unsigned char   ar_hln;	/* length of hardware address   */
	unsigned char   ar_pln;	/* length of protocol address   */
	__be16      ar_op;	/* ARP opcode (command)     */

	/* Ethernet+IPv4 specific members. */
	unsigned char       ar_sha[ETH_ALEN];	/* sender hardware address  */
	unsigned char       ar_sip[4];		/* sender IP address        */
	unsigned char       ar_tha[ETH_ALEN];	/* target hardware address  */
	unsigned char       ar_tip[4];		/* target IP address        */
} __packed;

static inline bool ovs_identifier_is_ufid(const struct sw_flow_id *sfid)
{
	return sfid->ufid_len;
}

static inline bool ovs_identifier_is_key(const struct sw_flow_id *sfid)
{
	return !ovs_identifier_is_ufid(sfid);
}

void ovs_flow_stats_update(struct sw_flow *, __be16 tcp_flags,
			   const struct sk_buff *);
void ovs_flow_stats_get(const struct sw_flow *, struct ovs_flow_stats *,
			unsigned long *used, __be16 *tcp_flags);
void ovs_flow_stats_clear(struct sw_flow *);
u64 ovs_flow_used_time(unsigned long flow_jiffies);

/* Update the non-metadata part of the flow key using skb. */
int ovs_flow_key_update(struct sk_buff *skb, struct sw_flow_key *key);
int ovs_flow_key_extract(const struct ip_tunnel_info *tun_info,
			 struct sk_buff *skb,
			 struct sw_flow_key *key);
/* Extract key from packet coming from userspace. */
int ovs_flow_key_extract_userspace(struct net *net, const struct nlattr *attr,
				   struct sk_buff *skb,
				   struct sw_flow_key *key, bool log);

#endif /* flow.h */
