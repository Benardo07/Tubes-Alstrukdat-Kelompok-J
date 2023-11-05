# include "prioqueue.h"
# include <stdio.h>

void CreatePrioQueue(PrioQueue *Q){
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

boolean IsPrioQueueEmpty (PrioQueue Q){
    return (Head(Q) == Nil & Tail(Q) == Nil);
};

boolean IsPrioQueueFull (PrioQueue Q){
    return (lengthPrioQueue(Q) == MaxEl(Q));
};

int lengthPrioQueue (PrioQueue Q){
     if(IsPrioQueueEmpty(Q)){
        return 0;
    }else{
        if(Head(Q)<=Tail(Q)){
            return (Tail(Q)-Head(Q) +1);
        }else{
            return(MaxEl(Q) + (Tail(Q)-Head(Q)+1));
        }
    }
};

void EnqueuePrio (PrioQueue * Q, infotype X){
    if(IsPrioQueueEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoHead(*Q) =  X;
    }else{
        Tail(*Q) = (Tail(*Q)+1) % MaxEl(*Q);
        InfoTail(*Q) = X;

        int len = lengthPrioQueue(*Q);
        int i;
        int current, next;
        infotype temp;

        for(i=0;i<len-1;i++){
            current = Tail(*Q) - i;
            if (current < 0){
                current += MaxEl(*Q);
            }else{
                current = current;
            }

            next = current - 1;
            if(next < 0){
                next += MaxEl(*Q);
            }else{
                next = next;
            }

            if(Prio(Elmt(*Q,current)) < Prio(Elmt(*Q,next))){
                temp = Elmt(*Q,current);
                Elmt(*Q,current) = Elmt(*Q,next);
                Elmt(*Q,next) = temp;
            }
        }
    }
};

void DequeuePrio (PrioQueue * Q, infotype * X){
    * X = InfoHead(*Q);
    if(lengthPrioQueue(*Q)==1){
        Head(*Q) =  -1;
        Tail(*Q) =  -1;
    }else{
        Head(*Q) = (Head(*Q)+1) % MaxEl(*Q);
    }
};

void DisplayPrioQueue(PrioQueue Q) {
    int i = Head(Q);
    int count = lengthPrioQueue(Q);

    printf("[");
    for (int j = 0; j < count; j++) {
        printf("(%d,%d)", Prio(Elmt(Q, i)), Info(Elmt(Q, i)));
        i = (i + 1) % MaxEl(Q);
        if (j < count - 1) {
            printf(",");
        }
    }
    printf("]\n");
}
