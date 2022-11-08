#define hash(v, M) (v % M)
#define hashTwo(v, M) (v % 97 + 1)

typedef struct Item
{
    int chave;
    long e1, e2;
    long elemento;
} Item;

Item NULLItem = {0, 0, 0, 0};
#define key(x) (x.chave)
#define less(a, b) (key(a) < key(b))
#define null(A) (key(ht[A]) == key(NULLItem))

static int N, M;
static Item *ht;

void expand(){
    int i;
    Item *t = ht;
    ht = malloc(sizeof(Item)*M*2);
    M = M*2;
    for(i=0; i<M/2; i++){
        if(key(t[i]) != key(NULLItem)){
            htInsert(t[i]);
        } 
    }
    free(t);
}

void htInsert(Item item)
{
    int v = key(item);
    int i = hash(v, M);
    int k = hashTwo(v, M);
    while (!null(i))
    {
        i = (i + k) % M;
    }
    ht[i] = item;
    N++;
    if(N >= M/2){
        expand();
    }
}

Item htSearch(int v)
{
    int i = hash(v, M);
    int k = hashTwo(v, M);
    while (!null(i))
    {
         if(v ==key(ht[i])){
            return ht[i];
         }else{
            i = (i + k) % M;
         }
    }
    return NULLItem;
}
