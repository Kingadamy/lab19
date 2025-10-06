#include <iostream>
#include <vector>
#include <fstream>   
#include <cstdlib>   
#include <ctime> 


using namespace std;

struct Node{   // create a struct for the node
   double rating;
   string comments;
   Node* next;
};

class Movie{ // create movie class
    private:
        string title;
        Node *head;
    
    public:
        Movie(string movieTitle); //  constructor
        void addAtHead(double rating, string comments); // add at head 
        void display(); // display 
        
        string getTitle(); // getter for title
        void setTitle(string movieTitle); // setter for title

};

Movie::Movie(string movieTitle) {  // implementation
    title = movieTitle;
    head = nullptr;
}

void Movie::addAtHead(double rating, string comments) {  // implementation
    struct Node *newNode = new Node; // create it here
    newNode -> rating = rating; // input data
    newNode -> comments = comments; //input data
    newNode -> next = head; // point new node to head
    head = newNode; // move head to point to new node

}

string Movie::getTitle() { // implementation
    return title;
}


void Movie::display() {
    int count = 1; // review #
    double sum = 0; // total rating
    int total = 0; // number of reviews

    struct Node *temp = head; // transverse the list
    while(temp != nullptr){
        cout << "\t> Review #" << count << ": " << temp->rating << ": " << temp->comments << endl;
        
        sum += temp->rating; // sum of ratings
        total++;  // how many reviews there are
        count++;  // add review #
        
        temp = temp->next;

    }


          // find averege
    if (total > 0) {
        cout << "\t> Average: " << (sum / total) << endl;
    }
  
}

void Movie::setTitle(string movieTitle) {
    // set the title
    title = movieTitle;
}



int main(){

    srand(time(0)); //  random number generator

      ifstream inFile("data.txt");
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    
    vector<Movie> movies;  //using a vectore to store the movies

    Movie movie1("The Matrix");
    Movie movie2("Inception");
    Movie movie3("Interstellar");
    Movie movie4("The Dark Knight");
    
    // Add movies to vector
    movies.push_back(movie1);
    movies.push_back(movie2);
    movies.push_back(movie3);
    movies.push_back(movie4);

 
    return 0;

}



