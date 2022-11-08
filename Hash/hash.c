#define hash(v, M) (v % M)
//#define hash(v, M) (618033 * (unsigned)v)%M)

typedef struct item
{
    int chave;
    long e1, e2;
    long elemento;
} item;

item NULLItem = {0, 0, 0, 0};
#define key(x) (x.chave)
#define less(a, b) (key(a) < key(b))
#define null(A) (key(ht[A]) == key(NULLItem))

static int N, M;
static item *ht;

void htInit(int max)
{
    int i;
    N = 0, M = 2 * max;
    ht = malloc(sizeof(item) * M);
    for (i = 0; i < M; i++)
    {
        ht[i] = NULLItem;
    }
}

int htCount()
{
    return N;
}

void htInsert(item iten)
{
    int v = key(iten);
    int i = hash(v, M);
    while (!null(i))
    {
        i = (i + 1) % M;
    }
}

item htSearch(int v)
{
    int i = hash(v, M);
    while(!null(i)){
        if(eq(v, key(ht[i]))){
            return ht[i];
        }else{
            i=(i+1)%M;
        }
    }
    return NULLItem;
}