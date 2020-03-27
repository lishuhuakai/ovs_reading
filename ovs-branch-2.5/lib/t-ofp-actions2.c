/* Generated automatically; do not modify!     -*- buffer-read-only: t -*- */

static inline void
put_OFPAT_SET_TP_SRC(struct ofpbuf *openflow, ovs_be16 arg);

static inline struct nx_action_conntrack *
put_NXAST_CT(struct ofpbuf *openflow);

static inline struct nx_action_controller *
put_NXAST_CONTROLLER(struct ofpbuf *openflow);

static inline void
put_NXAST_EXIT(struct ofpbuf *openflow);

static inline void
put_NXAST_POP_QUEUE(struct ofpbuf *openflow);

static inline void
put_OFPAT10_SET_VLAN_VID(struct ofpbuf *openflow, uint16_t arg);

static inline struct ofp15_action_copy_field *
put_OFPAT15_COPY_FIELD(struct ofpbuf *openflow);

static inline struct nx_action_conjunction *
put_NXAST_CONJUNCTION(struct ofpbuf *openflow);

static inline void
put_NXAST_RESUBMIT(struct ofpbuf *openflow, uint16_t arg);

static inline void
put_OFPAT11_SET_VLAN_VID(struct ofpbuf *openflow, uint16_t arg);

static inline struct nx_action_multipath *
put_NXAST_MULTIPATH(struct ofpbuf *openflow);

static inline void
put_NXAST_SET_TUNNEL(struct ofpbuf *openflow, uint32_t arg);

static inline struct nx_action_resubmit *
put_NXAST_RESUBMIT_TABLE(struct ofpbuf *openflow);

static inline struct nx_action_write_metadata *
put_NXAST_WRITE_METADATA(struct ofpbuf *openflow);

static inline void
put_OFPAT_PUSH_MPLS(struct ofpbuf *openflow, enum ofp_version version, ovs_be16 arg);

static inline struct nx_action_bundle *
put_NXAST_BUNDLE(struct ofpbuf *openflow);

static inline void
put_OFPAT10_STRIP_VLAN(struct ofpbuf *openflow);

static inline struct ofp_action_dl_addr *
put_OFPAT_SET_DL_DST(struct ofpbuf *openflow, enum ofp_version version);

static inline struct onf_action_copy_field *
put_ONFACT13_COPY_FIELD(struct ofpbuf *openflow);

static inline struct nx_action_learn *
put_NXAST_LEARN(struct ofpbuf *openflow);

static inline void
put_OFPAT11_SET_NW_TTL(struct ofpbuf *openflow, uint8_t arg);

static inline void
put_OFPAT11_SET_NW_ECN(struct ofpbuf *openflow, uint8_t arg);

static inline void
put_OFPAT11_POP_VLAN(struct ofpbuf *openflow);

static inline struct nx_action_sample *
put_NXAST_SAMPLE(struct ofpbuf *openflow);

static inline struct nx_action_fin_timeout *
put_NXAST_FIN_TIMEOUT(struct ofpbuf *openflow);

static inline struct ofp11_action_output *
put_OFPAT11_OUTPUT(struct ofpbuf *openflow);

static inline void
put_OFPAT11_SET_VLAN_PCP(struct ofpbuf *openflow, uint8_t arg);

static inline struct ofp12_action_set_field *
put_OFPAT15_SET_FIELD(struct ofpbuf *openflow);

static inline void
put_NXAST_DEBUG_RECIRC(struct ofpbuf *openflow);

static inline void
put_OFPAT_SET_NW_SRC(struct ofpbuf *openflow, enum ofp_version version, ovs_be32 arg);

static inline struct ofp10_action_enqueue *
put_OFPAT10_ENQUEUE(struct ofpbuf *openflow);

static inline struct nx_action_cnt_ids *
put_NXAST_DEC_TTL_CNT_IDS(struct ofpbuf *openflow);

static inline struct nx_action_reg_move *
put_NXAST_REG_MOVE(struct ofpbuf *openflow);

static inline struct nx_action_stack *
put_NXAST_STACK_POP(struct ofpbuf *openflow);

static inline void
put_OFPAT_SET_QUEUE(struct ofpbuf *openflow, enum ofp_version version, uint32_t arg);

static inline void
put_OFPAT10_SET_VLAN_PCP(struct ofpbuf *openflow, uint8_t arg);

static inline struct nx_action_note *
put_NXAST_NOTE(struct ofpbuf *openflow);

static inline void
put_OFPAT_DEC_NW_TTL(struct ofpbuf *openflow, enum ofp_version version);

static inline struct ofp_action_dl_addr *
put_OFPAT_SET_DL_SRC(struct ofpbuf *openflow, enum ofp_version version);

static inline void
put_OFPAT_SET_MPLS_LABEL(struct ofpbuf *openflow, enum ofp_version version, ovs_be32 arg);

static inline void
put_OFPAT_POP_MPLS(struct ofpbuf *openflow, enum ofp_version version, ovs_be16 arg);

static inline void
put_OFPAT_SET_MPLS_TTL(struct ofpbuf *openflow, enum ofp_version version, uint8_t arg);

static inline struct ofp12_action_set_field *
put_OFPAT12_SET_FIELD(struct ofpbuf *openflow);

static inline struct nx_action_bundle *
put_NXAST_BUNDLE_LOAD(struct ofpbuf *openflow);

static inline struct nx_action_output_reg *
put_NXAST_OUTPUT_REG(struct ofpbuf *openflow);

static inline void
put_OFPAT_SET_NW_DST(struct ofpbuf *openflow, enum ofp_version version, ovs_be32 arg);

static inline void
put_OFPAT11_PUSH_VLAN(struct ofpbuf *openflow, ovs_be16 arg);

static inline struct ofp10_action_output *
put_OFPAT10_OUTPUT(struct ofpbuf *openflow);

static inline void
put_NXAST_SET_TUNNEL64(struct ofpbuf *openflow, uint64_t arg);

static inline struct nx_action_reg_load *
put_NXAST_REG_LOAD(struct ofpbuf *openflow);

static inline void
put_OFPAT_SET_TP_DST(struct ofpbuf *openflow, ovs_be16 arg);

static inline void
put_OFPAT_DEC_MPLS_TTL(struct ofpbuf *openflow, enum ofp_version version);

static inline void
put_OFPAT11_GROUP(struct ofpbuf *openflow, uint32_t arg);

static inline struct nx_action_stack *
put_NXAST_STACK_PUSH(struct ofpbuf *openflow);

static inline void
put_OFPAT_SET_NW_TOS(struct ofpbuf *openflow, enum ofp_version version, uint8_t arg);

static inline void
put_OFPAT_SET_MPLS_TC(struct ofpbuf *openflow, enum ofp_version version, uint8_t arg);

static inline struct nx_action_output_reg2 *
put_NXAST_OUTPUT_REG2(struct ofpbuf *openflow);

static inline struct nx_action_reg_load2 *
put_NXAST_REG_LOAD2(struct ofpbuf *openflow);

static enum ofperr decode_OFPAT_RAW_SET_TP_SRC(ovs_be16, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_CT(const struct nx_action_conntrack *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_CONTROLLER(const struct nx_action_controller *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_EXIT(struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_POP_QUEUE(struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW10_SET_VLAN_VID(uint16_t, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW15_COPY_FIELD(const struct ofp15_action_copy_field *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_CONJUNCTION(const struct nx_action_conjunction *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_RESUBMIT(uint16_t, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW11_SET_VLAN_VID(uint16_t, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_MULTIPATH(const struct nx_action_multipath *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_SET_TUNNEL(uint32_t, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_RESUBMIT_TABLE(const struct nx_action_resubmit *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_WRITE_METADATA(const struct nx_action_write_metadata *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW_PUSH_MPLS(ovs_be16, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_BUNDLE(const struct nx_action_bundle *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW10_STRIP_VLAN(struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW_SET_DL_DST(const struct ofp_action_dl_addr *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_ONFACT_RAW13_COPY_FIELD(const struct onf_action_copy_field *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_LEARN(const struct nx_action_learn *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW11_SET_NW_TTL(uint8_t, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW11_SET_NW_ECN(uint8_t, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW11_POP_VLAN(struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_SAMPLE(const struct nx_action_sample *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_FIN_TIMEOUT(const struct nx_action_fin_timeout *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW11_OUTPUT(const struct ofp11_action_output *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW11_SET_VLAN_PCP(uint8_t, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW15_SET_FIELD(const struct ofp12_action_set_field *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_DEBUG_RECIRC(struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW_SET_NW_SRC(ovs_be32, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW10_ENQUEUE(const struct ofp10_action_enqueue *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_DEC_TTL_CNT_IDS(const struct nx_action_cnt_ids *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_REG_MOVE(const struct nx_action_reg_move *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_STACK_POP(const struct nx_action_stack *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW_SET_QUEUE(uint32_t, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW10_SET_VLAN_PCP(uint8_t, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_NOTE(const struct nx_action_note *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW_DEC_NW_TTL(struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW_SET_DL_SRC(const struct ofp_action_dl_addr *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW_SET_MPLS_LABEL(ovs_be32, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW_POP_MPLS(ovs_be16, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW_SET_MPLS_TTL(uint8_t, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW12_SET_FIELD(const struct ofp12_action_set_field *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_BUNDLE_LOAD(const struct nx_action_bundle *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_OUTPUT_REG(const struct nx_action_output_reg *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW_SET_NW_DST(ovs_be32, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW11_PUSH_VLAN(ovs_be16, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW10_OUTPUT(const struct ofp10_action_output *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_SET_TUNNEL64(uint64_t, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_REG_LOAD(const struct nx_action_reg_load *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW_SET_TP_DST(ovs_be16, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW_DEC_MPLS_TTL(struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW11_GROUP(uint32_t, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_STACK_PUSH(const struct nx_action_stack *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW_SET_NW_TOS(uint8_t, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_OFPAT_RAW_SET_MPLS_TC(uint8_t, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_OUTPUT_REG2(const struct nx_action_output_reg2 *, enum ofp_version, struct ofpbuf *);
static enum ofperr decode_NXAST_RAW_REG_LOAD2(const struct nx_action_reg_load2 *, enum ofp_version, struct ofpbuf *);

static enum ofperr ofpact_decode(const struct ofp_action_header *,
                                 enum ofp_raw_action_type raw,
                                 enum ofp_version version,
                                 uint64_t arg, struct ofpbuf *out);

