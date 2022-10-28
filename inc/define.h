#ifndef  __DEFINE_H__
#define  __DEFINE_H__

typedef float DATA_TYPE;
typedef int INT;
typedef void VOID;

#define PRECISION "%.5lf\t"

#define MALLOC(n, type) \
         ((type *)malloc( (n) * sizeof(type)))

#define FREE(p)             \
         if(p!=NULL)         \
         {                   \
               free(p);       \
               p = NULL;     \
         }


#endif