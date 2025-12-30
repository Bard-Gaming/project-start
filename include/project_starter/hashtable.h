/*
** BARDSHELL PROJECT, 2025
** Module: Hashtable
** File description:
** Header file for everything
** related to hashtables
*/

#ifndef PROJECT_STARTER_HASHTABLE_H
    #define PROJECT_STARTER_HASHTABLE_H
    #include <stddef.h>

    #define HASHTABLE_INIT_POWER 5   // initial capacity: 2^X
    #define HASHTABLE_LOAD_FACTOR 2  // ideal range: between 1 and 3
    #define HASHING_FACTOR 1907      // ideally a prime number


typedef struct _HashtableBucket {
    char *key;
    void *data;
    struct _HashtableBucket *next;
} HashtableBucket;

typedef struct {
    HashtableBucket **buckets;
    size_t count;
    unsigned char capacity_power;  // capacity in powers of 2
} Hashtable;


void hashtable_init(Hashtable *table);
void hashtable_delete(Hashtable *table);
void hashtable_set(Hashtable *table, const char *key, void *value);
void *hashtable_get(const Hashtable *table, const char *key);

size_t hashtable_hash(unsigned char capacity_power, const char *key);


#endif
