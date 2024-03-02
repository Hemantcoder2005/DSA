#include<iostream>
using namespace std;

class Node{
	public:
	int val;
	Node* next;

	//constructor
	Node(int val){
		this->val=val;
		this->next=NULL;
	}
	

};


void print(Node* head){

	while(head!=NULL){
	
	cout<<head->val<<" ";
	head=head->next;

	}


}

void insert(Node* &head,int val,int position){

	Node* curr=head;
	int i=1;
	while(i<position-1 and curr!=NULL){
		
		curr=curr->next;
		i++;	
	}


	Node* temp=new Node(val);
	if (curr==head){
		//Insert at head
		
		temp->next=head;
		head=temp;	
		return ;
	}
	else if(curr==NULL){
		//Insert at Tail
		curr->next=temp;
		return;
	}

	
	temp->next=curr->next;
	curr->next=temp;
}

int search(Node *head,int target){
	int at=1;
	while(head!=NULL){
		if(head->val==target){
		
			return at;
		}
	at++;
	head=head->next;

	}

	return -1;

}

void deleteNode(Node* &head,int pos){
	if(pos==1){
		head=head->next;

	
		return;
	}
	Node* curr=head;
	int i=1;
	while(i<pos-1 && curr->next!=NULL )
	{
	
		curr=curr->next;
		i++;
	
	}

	Node* temp=curr->next;
	curr->next=temp->next;
	


}


void reverse(Node* &head){
	
	if(head->next==NULL)
	{
	return;
		
	}
	Node* prev=NULL;
	Node* curr=head;
	Node* next=head->next;
	
	while(curr!=NULL)
	{
	curr->next=prev;
	
	
	prev=curr;
	curr=next;
	if(curr==NULL){
		break;
	
	}
	next=next->next;

	
	
	}
	head= prev;
}


float getmid(Node* head){
	//Base Case
	if(head==NULL){
		return -1;
	}

	Node* slow=head;
	Node* fast=head;
	Node* prev=NULL;

	while (fast!=NULL and fast->next!=NULL)
	{
		fast=fast->next->next;
		prev=slow;
		slow=slow->next;
	}

	if (fast==NULL){
		return float(prev->val+slow->val)/2;
	}
	return (slow->val);	
}

void rotate(Node* &head,int pos){
	//Base Case
	if(head==NULL || head->next==NULL){
		return ;
	}
	Node* curr=head;
	Node* cut=NULL;
	while (curr!=NULL)
	{	
		if (curr->next==NULL && pos==1){
			curr->next=head;
			head=cut;
		}
		else if (pos!=1){
			pos--;
		}
		else{
			cut=curr->next;
			curr->next=NULL;
			curr=cut;
		}
	}
	
	

}
int main(){

	Node* dummy=new Node(0);
	Node* curr=dummy;
	int size;
	cout<<"Enter the size of the linked list = ";
	cin>>size;
	
	for(int i=0;i<size;i++){
		
		int x;
		cout<<"Enter "<<i+1<<" value = ";
		cin>>x;

		Node* temp=new Node(x);
		curr->next=temp;
		curr=curr->next;
	}

	Node* head=dummy->next;
	
        bool run =true;
	while(run){
		cout<<endl;
		cout<<"Select Your Choice:"<<endl;
		cout<<"1.Search Node"<<endl;
		cout<<"2.Insert Node"<<endl;
		cout<<"3.Delete Node"<<endl;
		cout<<"4.Reverse Linked List"<<endl;
		cout<<"5.Get Median Value"<<endl;
		cout<<"6.Print Linked List"<<endl;
		cout<<"7.Rotate about kth position"<<endl;
		cout<<"8.Quit"<<endl;
		
		cout<<endl;
		int choice;
		cout<<"Enter Your Choice from (1-8) = ";
		cin>>choice;
		
		cout<<endl;
	if(choice==1){
	int target;
	cout<<"Enter the targeted value = ";
	cin>>target;

	int ans=search(head,target);
	if(ans==-1){
		cout<<"Didn't get!";

	}

	else{
	
		cout<<"Found at "<<ans<<endl;
	}

	}
	else if(choice==2){
	int val;
	cout<<"Enter the value to Insert = ";
	cin>>val;

	int pos;
	cout<<"Enter the position at which to be insert = ";
	cin>>pos;
	cout<<endl;
	insert(head,val,pos);
	print(head);
	
	
	}
	else if(choice ==3){
	
	cout<<"Enter the position to delete node = "<<endl;
	int pos;
	cin>>pos;

	deleteNode(head,pos);
	print(head);
	}
	else if(choice==4){
		reverse(head);
		print(head);
	}

	else if(choice==5){
		print(head);
		cout<<"Median Value is "<<getmid(head)<<endl;
	}
	else if(choice==6){
		print(head);
	}

	else if(choice==7){
		print(head);
		cout<<endl;
		rotate(head,2);
		print(head);
	}
	else if(choice==8){
	
		return 0;
	}
	else{
	
		cout<<"Enter Valid choice from 1-6"<<endl;
	}
	
	}
}
