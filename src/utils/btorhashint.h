/*  Boolector: Satisfiablity Modulo Theories (SMT) solver.
 *
 *  Copyright (C) 2015-2016 Mathias Preiner.
 *  Copyright (C) 2016 Aina Niemetz.
 *
 *  All rights reserved.
 *
 *  This file is part of Boolector.
 *  See COPYING for more information on using this software.
 */

#ifndef BTOR_INT_HASH_H_INCLUDED
#define BTOR_INT_HASH_H_INCLUDED

#include <stdbool.h>
#include <stdint.h>
#include "utils/btorhash.h"
#include "utils/btormem.h"

/*------------------------------------------------------------------------*/

struct BtorIntHashTable
{
  BtorMemMgr *mm;
  size_t count;
  size_t size;
  int32_t *keys;
  uint8_t *hop_info; /* displacement information */
  BtorHashTableData *data;
};

typedef struct BtorIntHashTable BtorIntHashTable;

/*------------------------------------------------------------------------*/
/* hash table                                                             */
/*------------------------------------------------------------------------*/

/* Create new int32_t hash table. */
BtorIntHashTable *btor_new_int_hash_table (BtorMemMgr *);

/* Free int32_t hash table. */
void btor_delete_int_hash_table (BtorIntHashTable *);

/* Returns the size of the BtorIntHashTable in Byte. */
size_t btor_size_int_hash_table (BtorIntHashTable *);

/* Add 'key' to the hash table and return the position at which 'key' is
 * stored in the keys array. */
size_t btor_add_int_hash_table (BtorIntHashTable *, int32_t key);

/* Check whether 'key' is in the hash table. */
bool btor_contains_int_hash_table (BtorIntHashTable *, int32_t key);

/* Remove 'key' from the hash table and return the position at which 'key'
 * was stored in the keys array. */
size_t btor_remove_int_hash_table (BtorIntHashTable *, int32_t key);

/* Returns the position at which 'key' is stored in the keys array. It returns
 * 'size' of the hash table if 'key' could not be found. */
// TODO (ma): remove
size_t btor_get_pos_int_hash_table (BtorIntHashTable *, int32_t key);

BtorIntHashTable *btor_clone_int_hash_table (BtorMemMgr *mm,
                                             BtorIntHashTable *table);

/*------------------------------------------------------------------------*/
/* hash map                                                               */
/*------------------------------------------------------------------------*/

BtorIntHashTable *btor_new_int_hash_map (BtorMemMgr *);

bool btor_contains_int_hash_map (BtorIntHashTable *, int32_t key);

void btor_remove_int_hash_map (BtorIntHashTable *,
                               int32_t key,
                               BtorHashTableData *stored_data);

BtorHashTableData *btor_add_int_hash_map (BtorIntHashTable *, int32_t key);
BtorHashTableData *btor_get_int_hash_map (BtorIntHashTable *, int32_t key);

void btor_delete_int_hash_map (BtorIntHashTable *);

BtorIntHashTable *btor_clone_int_hash_map (BtorMemMgr *mm,
                                           BtorIntHashTable *table,
                                           BtorCloneHashTableData cdata,
                                           const void *data_map);

/*------------------------------------------------------------------------*/
/* iterators     		                                          */
/*------------------------------------------------------------------------*/

typedef struct BtorIntHashTableIterator
{
  size_t cur_pos;
  const BtorIntHashTable *t;
} BtorIntHashTableIterator;

void btor_init_int_hash_table_iterator (BtorIntHashTableIterator *it,
                                        const BtorIntHashTable *t);

bool btor_has_next_int_hash_table_iterator (const BtorIntHashTableIterator *it);

int32_t btor_next_int_hash_table_iterator (BtorIntHashTableIterator *it);

BtorHashTableData *btor_next_data_int_hash_table_iterator (
    BtorIntHashTableIterator *it);

/*------------------------------------------------------------------------*/

#endif
