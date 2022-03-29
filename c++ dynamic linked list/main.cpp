#include <iostream>
using namespace std;

template <typename T>

class LinkedList {

  struct Node {
    int ID;
    T data;
    Node* next;
  }; 

  Node* head = NULL;

  public:
  void add(int num, T newData) {
    if (head != NULL && find(num)) {
      cout<<"This node ID is already in the lsit!" << endl;
      return;
    }
    Node* node = new Node();
    node->ID = num;
    node->data = newData;
    node->next = NULL;
    if (head == NULL) {
      head = node;
    } else if (head->next == NULL) {
      if (head->ID > num) {
        node->next = head;
        head = node;
      } else {
        head->next = node;
      }
    } else {
      Node* curr = head;
      while (curr->next != NULL && curr->next->ID < num) {
        curr = curr->next;
      }
      node->next = curr->next;
      curr->next = node;
    }
    cout<<"New node added!" <<endl;
    
  }


  void del(int num) {
    if (head == NULL) {
      cout << "empty list, cannot perform deletion!" << endl;
      return;
    }
    if (find(num)) {
      if (head->ID == num) {
        head = head->next;
      } else {
        Node* curr = head;
        while (curr->next->ID != num) {
          curr = curr->next;
        }
        curr->next = curr->next->next;
        
        cout<<"the node is deleted!" << endl;
      }
    } else {
      cout << "No such element!" << endl;
    }
  }


  bool find(int num) {
    if (head == NULL) {
      cout << "cannot find in an empty list!" << endl;
      return false;
    }
    Node* curr = head;
    while (curr!= NULL && curr->ID != num) {
      curr = curr->next;
    }
    if (curr==NULL) {
      cout << "element ID not found!" << endl;
      return false;
    }
    cout << "element ID: " << num << " found!" << endl;
    cout << "The data is :" << curr->data << endl; 
    return true;
  }

  void modify(int num, T newData) {
    if (!find(num)) {
      cout << "No such element and therefore cannot make the modification." << endl;
    } else {
      cout << "before modification: " << endl;
      display();
      Node* curr = head;
      while (curr->ID != num) {
        curr = curr->next;
      }
      curr->data = newData;
      cout << "after modification: " << endl;
      display();
    }
  }

  void display() {
    Node* curr = head;
    cout << "The linked list is: ";
    while (curr != NULL) {
      cout << "|ID: " << curr -> ID << "|data: " << curr -> data << "|";
      cout << " -> ";
      curr = curr -> next;
    }
    cout << "NULL \n";
  }

  void purge() {
    if (head != NULL) {
      head = NULL;
      cout<<"The list is purged!" <<endl;
    }
  }

};




int main() {
  bool run = true;
  bool have = false;
  LinkedList<int>* list = new LinkedList<int>();
  
  do {
    int x;
    cout<<"============================"<<endl;
    cout<<"Please enter a command#: "<<endl;
    cout<<"1 cerate the list" << endl;
    cout<<"2 add a node"<<endl;
    cout<<"3 delete a node"<<endl;
    cout<<"4 find a node"<<endl;
    cout<<"5 display the list"<<endl;
    cout<<"6 modify a node"<<endl;
    cout<<"7 purge the list"<<endl;
    cout<<"==========================="<<endl;
      
    cin>>x;
    if (!have && x != 1) {
      cout << "Please create the list before you do any operations!" << endl;
      continue;
    } else if (x==1 && have) {
      cout << "Don't be greedy! You already have one!" << endl;
      continue;
    } else if (x==1 && !have) {
      
      have = true;
      cout << "Your list is created!!" << endl;
      continue;
    }
    
    switch(x) {
      case 2: {
        int num, newData;
        cout<<"Please enter the ID: " <<endl;
        cin>>num;
        cout<<"Please enter the data: " <<endl;
        cin>>newData;
        list->add(num, newData);
        break;
      }
      case 3: {
        int num;
        cout<<"Please enter the ID: " <<endl;
        cin>>num;
        list->del(num);
        break;
      }
      case 4: {
        int num;
        cout<<"Please enter the ID: " <<endl;
        cin>>num;
        list->find(num);
        break;
      }
      case 5: {
        list->display();
        break;
      }
      case 6: {
        list->display();
        int num, newData;
        cout<<"Please enter the ID you want to modify: " <<endl;
        cin>>num;
        cout<<"Please enter the data: " <<endl;
        cin>>newData;
        list->modify(num, newData);
        break;
      }
      case 7: {
        list->purge();
        break;
      }
      default: {
        cout<<"Invalid Choice!"<<endl;
      }
    }

    cout << "Do you want to continue? type any number to continue or type 0 to exit the manual." <<endl;
    int a;
    cin >> a;
    if (a == 0) {
      run = false;
      have = false;
    } else {
      run = true;
    }
  }while(run);    
  
  cout << "the porgam is ending..." <<endl;
  
  return 0;
}