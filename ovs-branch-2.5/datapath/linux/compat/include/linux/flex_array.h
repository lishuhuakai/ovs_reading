#ifndef __LINUX_FLEX_ARRAY_WRAPPER_H
#define __LINUX_FLEX_ARRAY_WRAPPER_H

#include <linux/version.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,0,0)
#include_next <linux/flex_array.h>
#else

#include <linux/reciprocal_div.h>
#include <linux/types.h>
#include <asm/page.h>

#define FLEX_ARRAY_PART_SIZE PAGE_SIZE
#define FLEX_ARRAY_BASE_SIZE PAGE_SIZE

struct flex_array_part;

/*
 * This is meant to replace cases where an array-like
 * structure has gotten too big to fit into kmalloc()
 * and the developer is getting tempted to use
 * vmalloc().
 */
/* 流表hash桶 */
struct flex_array {
	union {
		struct {
			int element_size; /* 每个元素的大小 */
			int total_nr_elements; /* 元素的总个数 */
			int elems_per_part; /* 每个part包含的元素个数 */
			struct reciprocal_value reciprocal_elems;
            /*
              当元素占用的空间(element_size * total_nr_elements)大于
              FLEX_ARRAY_BASE_BYTES_LEFT时,
              parts包含多个分页空间,否则只包含一页空间即可
             */
			struct flex_array_part *parts[];
		};
		/*
		 * This little trick makes sure that
		 * sizeof(flex_array) == PAGE_SIZE
		 */
		/* 这里的padding仅仅只是一个占位符而已,保证flex array的大小至少为一页 */
		char padding[FLEX_ARRAY_BASE_SIZE]; /* 一页大小的page size */
	};
};

/* Number of bytes left in base struct flex_array, excluding metadata */
#define FLEX_ARRAY_BASE_BYTES_LEFT					\
	(FLEX_ARRAY_BASE_SIZE - offsetof(struct flex_array, parts))

/* Number of pointers in base to struct flex_array_part pages */
#define FLEX_ARRAY_NR_BASE_PTRS						\
	(FLEX_ARRAY_BASE_BYTES_LEFT / sizeof(struct flex_array_part *))

/* Number of elements of size that fit in struct flex_array_part */
#define FLEX_ARRAY_ELEMENTS_PER_PART(size)				\
	(FLEX_ARRAY_PART_SIZE / size)

/*
 * Defines a statically allocated flex array and ensures its parameters are
 * valid.
 */
#define DEFINE_FLEX_ARRAY(__arrayname, __element_size, __total)		\
	struct flex_array __arrayname = { { {				\
		.element_size = (__element_size),			\
		.total_nr_elements = (__total),				\
	} } };								\
	static inline void __arrayname##_invalid_parameter(void)	\
	{								\
		BUILD_BUG_ON((__total) > FLEX_ARRAY_NR_BASE_PTRS *	\
			FLEX_ARRAY_ELEMENTS_PER_PART(__element_size));	\
	}

#define flex_array_alloc rpl_flex_array_alloc
struct flex_array *rpl_flex_array_alloc(int element_size, unsigned int total,
		gfp_t flags);

#define flex_array_prealloc rpl_flex_array_prealloc
int rpl_flex_array_prealloc(struct flex_array *fa, unsigned int start,
		unsigned int nr_elements, gfp_t flags);

#define flex_array_free rpl_flex_array_free
void rpl_flex_array_free(struct flex_array *fa);

#define flex_array_free_parts rpl_flex_array_free_parts
void rpl_flex_array_free_parts(struct flex_array *fa);

#define flex_array_put rpl_flex_array_put
int rpl_flex_array_put(struct flex_array *fa, unsigned int element_nr, void *src,
		gfp_t flags);

#define flex_array_clear rpl_flex_array_clear
int rpl_flex_array_clear(struct flex_array *fa, unsigned int element_nr);

#define flex_array_get rpl_flex_array_get
void *rpl_flex_array_get(struct flex_array *fa, unsigned int element_nr);

#define flex_array_shrink rpl_flex_array_shrink
int rpl_flex_array_shrink(struct flex_array *fa);

#define flex_array_put_ptr rpl_flex_array_put_ptr
#define rpl_flex_array_put_ptr(fa, nr, src, gfp) \
	flex_array_put(fa, nr, (void *)&(src), gfp)

#define flex_array_get_ptr rpl_flex_array_get_ptr
void *rpl_flex_array_get_ptr(struct flex_array *fa, unsigned int element_nr);

#endif /* Linux version < 3.0.0 */
#endif /* __LINUX_FLEX_ARRAY_WRAPPER_H */
