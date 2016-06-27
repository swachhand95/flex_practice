#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
    float coef;
    int exp;
    Node* next;
};
class equation
{
    Node* first;
public:
    equation()
    {
        first=NULL;
    }
    void insert(float c,int p);
    void display();
    equation add(equation second);
    equation multiply(equation second);
};
equation equation::multiply(equation second)
{
    equation result;
    Node *p,*q;
    int pow;
    float coef;
    for(p=first;p!=NULL;p=p->next)
    {
        for(q=second.first;q!=NULL;q=q->next)
        {
            coef=q->coef*p->coef;
            pow=q->exp+p->exp;
            // cout<<"coeffient: "<<coef<<" power: "<<pow<<endl;
            result.insert(coef,pow);
        }
    }
    return result;
}
equation equation::add(equation second)
{
    equation result;
    Node *p,*q;
    p=first;q=second.first;
    float coef;
    int pow;
    cout<<p->coef<<endl;
    cout<<q->coef<<endl;
    while(p!=NULL || q!=NULL)
    {
       // cout<<"inside while\n";
      //  Node *newnode=new Node();

        if((p!=NULL && q!=NULL && p->exp > q->exp) || (p!=NULL&&q==NULL))
        {
           pow=p->exp;
           coef=p->coef;
           p=p->next;
        }
        else if((q!=NULL && p!=NULL && p->exp < q->exp) || (q!=NULL&&p==NULL))
        {
            pow=q->exp;
            coef=q->coef;
            q=q->next;
        }
        else if(p!=NULL && q!=NULL && p->exp == q->exp)
        {
            pow=p->exp;
            coef=p->coef+q->coef;
            cout<<coef<<endl;
            p=p->next;
            q=q->next;
        }


        result.insert(coef,pow);
    }
    return result;
}
void equation::display()
{
    Node* p=first;
    //cout<<"in display\n";
    while(p!=NULL)
    {

        cout<<abs(p->coef)<<"x^"<<p->exp<<" ";
        p=p->next;
        if(p!=NULL)
            {
                 if(p->coef>0)
                 cout<<"+ ";
                 else
                    cout<<"- ";
            }
    }
}
void equation::insert(float c,int po)
{
    Node* p=first;
    Node* prev=first;
    Node* newnode=new Node;
    newnode->coef=c;
    newnode->exp=po;
    if(first==NULL)
    {
        first=newnode;
        newnode->next=NULL;

    }
    else
    {
        while(p!=NULL && p->exp > newnode->exp)
        {
            //cout<<"inside while\n";
            prev=p;
            p=p->next;
        }
        //cout<<"outside\n";
        if( p!=NULL&&p->exp== newnode->exp)
        {
            p->coef=p->coef+newnode->coef;
        }
        else if(first==p)
        {
            newnode->next=first;
            first=newnode;
        }
        else
        {
            newnode->next=prev->next;
            prev->next=newnode;
        }
    }
}
int main()
{

    equation a,b,c;
    a.insert(5,3);
    a.insert(2,2);

    a.display();
    cout<<endl;

    b.insert(5,1);
    b.insert(1,0);
    b.insert(3,2);
    b.insert(10,3);

    b.display();
    cout << endl;

    c=a.multiply(b);
    cout<<endl;
    c.display();

    return 0;
}
