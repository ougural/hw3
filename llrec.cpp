#include "llrec.h"
//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivotRec(Node *&head, Node *&smaller, Node *&larger, int pivot){
	if(head == nullptr){
		smaller = nullptr;
		larger = nullptr;
	}
	else if(head->val > pivot){
		larger = head;
		return(llpivot(head->next, smaller, larger->next, pivot));
	}
	else{
		smaller = head;
		return(llpivot(head->next, smaller->next, larger, pivot));
	}
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	llpivotRec(head, smaller, larger, pivot);
	head = nullptr;
}

