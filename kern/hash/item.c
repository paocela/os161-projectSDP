#include <types.h>
#include <lib.h>
#include "item.h"
#include "st.h"


struct item {
  Key key;
  int index;
};


static Item tmp=NULL;

void item_init(void){
  tmp = kmalloc (sizeof(struct item));
}


Item ITEMscan (pid_t pid, vaddr_t addr, int index) {

    tmp->key.kaddr = addr;
    tmp->key.kpid = pid;
    tmp->index = index;
  

  return tmp;
}


int ITEMcheckvoid(Item data) {
  Key k1, k2;
  k2.kaddr = -1;
  k2.kpid = -1;
  k1 = KEYget(data);
  if (KEYcompare(k1,k2)==0)
    return 1;
  else
    return 0;
}



Item ITEMsetvoid(void) {  
  Item tmp = (Item) kmalloc(sizeof(struct item));
  KASSERT(tmp != NULL);
  tmp->key.kpid = -1;
  tmp->key.kaddr = -1;
  tmp->index = -1;
  return tmp;
}

Item ITEMsetnull(void) {  
  return NULL;
}

int  KEYcompare(Key k1, Key k2) {
  
    if (k1.kaddr == k2.kaddr && k1.kpid == k2.kpid){
        return 0;
    }
    return -1;
}

Key KEYget(Item data) {
  return data->key;
}