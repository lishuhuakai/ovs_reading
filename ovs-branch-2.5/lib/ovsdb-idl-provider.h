/* Copyright (c) 2009, 2010, 2011, 2012 Nicira, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OVSDB_IDL_PROVIDER_H
#define OVSDB_IDL_PROVIDER_H 1

#include "hmap.h"
#include "list.h"
#include "ovsdb-idl.h"
#include "ovsdb-types.h"
#include "shash.h"
#include "uuid.h"

struct ovsdb_idl_row {
    struct hmap_node hmap_node; /* In struct ovsdb_idl_table's 'rows'. */
    struct uuid uuid;           /* Row "_uuid" field. */
    /* 前向引用,引用的源头 */
    struct ovs_list src_arcs;   /* Forward arcs (ovsdb_idl_arc.src_node). */
    /* 反向引用,被别人引用 */
    struct ovs_list dst_arcs;   /* Backward arcs (ovsdb_idl_arc.dst_node). */
    struct ovsdb_idl_table *table; /* Containing table. */
    struct ovsdb_datum *old;    /* Committed data (null if orphaned). */

    /* Transactional data. */
    struct ovsdb_datum *new;    /* Modified data (null to delete row). */
    /* 前置条件 */
    unsigned long int *prereqs; /* Bitmap of columns to verify in "old". */
    /* 用于记录哪一列发生了修改 */
    unsigned long int *written; /* Bitmap of columns from "new" to write. */
    struct hmap_node txn_node;  /* Node in ovsdb_idl_txn's list. */

    unsigned int change_seqno[OVSDB_IDL_CHANGE_MAX];
    struct ovs_list track_node;
};

/* 用于记录关注的列 */
struct ovsdb_idl_column {
    char *name; /* 列的名称 */
    struct ovsdb_type type; /* 列的类型 */
    bool mutable; /* 是否可变 */
    void (*parse)(struct ovsdb_idl_row *, const struct ovsdb_datum *);
    void (*unparse)(struct ovsdb_idl_row *);
};

struct ovsdb_idl_table_class {
    char *name;
    bool is_root;
    const struct ovsdb_idl_column *columns;
    size_t n_columns;
    size_t allocation_size;
    void (*row_init)(struct ovsdb_idl_row *);
};

/* 用于镜像关注的表数据 */
struct ovsdb_idl_table {
    const struct ovsdb_idl_table_class *class; /* 引用表的元数据 */
    unsigned char *modes;    /* OVSDB_IDL_* bitmasks, indexed by column. */
    bool need_table;         /* Monitor table even if no columns are selected
                              * for replication. */
    struct shash columns;    /* Contains "const struct ovsdb_idl_column *"s. */
    /* rows用于记录所有的行 */
    struct hmap rows;        /* Contains "struct ovsdb_idl_row"s. */
    struct ovsdb_idl *idl;   /* Containing idl. */
    unsigned int change_seqno[OVSDB_IDL_CHANGE_MAX]; /* 序列值,如果发生更改,序列值会变化 */
	/* 用于追踪 */
    struct ovs_list track_list; /* Tracked rows (ovsdb_idl_row.track_node). */
};

/* 数据库的元数据 */
struct ovsdb_idl_class {
    const char *database;       /* <db-name> for this database. */
    const struct ovsdb_idl_table_class *tables;
    size_t n_tables;
};

struct ovsdb_idl_row *ovsdb_idl_get_row_arc(
    struct ovsdb_idl_row *src,
    struct ovsdb_idl_table_class *dst_table,
    const struct uuid *dst_uuid);

void ovsdb_idl_txn_verify(const struct ovsdb_idl_row *,
                          const struct ovsdb_idl_column *);

struct ovsdb_idl_txn *ovsdb_idl_txn_get(const struct ovsdb_idl_row *);

#endif /* ovsdb-idl-provider.h */
