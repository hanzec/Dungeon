#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include <stdint.h>

#ifndef HEAP_H
# define HEAP_H

# ifdef __cplusplus
extern "C" {
# endif

typedef struct heap_node {
    void *datum;
    uint32_t mark;
    uint32_t degree;
    struct heap_node *next;
    struct heap_node *prev;
    struct heap_node *parent;
    struct heap_node *child;
} heap_node_t;

typedef struct heap {
    heap_node_t *min;
    uint32_t size;
    int32_t (*compare)(const void *key, const void *with);
    void (*datum_delete)(void *);
} heap_t;


#define swap(a, b) ({    \
  typeof (a) _tmp = (a); \
  (a) = (b);             \
  (b) = _tmp;            \
})

#define splice_heap_node_lists(n1, n2) ({ \
  if ((n1) && (n2)) {                     \
    (n1)->next->prev = (n2)->prev;        \
    (n2)->prev->next = (n1)->next;        \
    (n1)->next = (n2);                    \
    (n2)->prev = (n1);                    \
  }                                       \
})

#define insert_heap_node_in_list(n, l) ({ \
  (n)->next = (l);                        \
  (n)->prev = (l)->prev;                  \
  (n)->prev->next = (n);                  \
  (l)->prev = (n);                        \
})

#define remove_heap_node_from_list(n) ({ \
  (n)->next->prev = (n)->prev;           \
  (n)->prev->next = (n)->next;           \
})

void heap_init(heap_t *h,
               int32_t (*compare)(const void *key, const void *with),
               void (*datum_delete)(void *));
void heap_delete(heap_t *h);
heap_node_t *heap_insert(heap_t *h, void *v);
void *heap_peek_min(heap_t *h);
void *heap_remove_min(heap_t *h);
int heap_combine(heap_t *h, heap_t *h1, heap_t *h2);
int heap_decrease_key(heap_t *h, heap_node_t *n, void *v);
int heap_decrease_key_no_replace(heap_t *h, heap_node_t *n);

# ifdef __cplusplus
}
# endif

#endif
