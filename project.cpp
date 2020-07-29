#include <iostream>
#include <map>
#include <vector>
using namespace std;

int price =0;
map<string, vector< pair<string, int> > > netbill;

map< int, pair<string, int> > vegp;
map< int, pair<string, int> > nonvegp;
map< int, pair<string, int> > veg;
map< int, pair<string, int> > nonveg;
map< int, pair<string, int> > sides;
map< int, pair<string, int> > beverage;
map< int, pair<string, int> > dessert;
map< int, string > softdrink;


class Pizza{
   
  void vegpizza(){
       

       cout<<"--------Veg Pizza-------"<<endl;
       for(auto itp: vegp)
       {
           cout<<itp.first<<". "<<itp.second.first<<" --> "<<itp.second.second<<endl;
       }
       cout<<"Press 0 to exit"<<endl;
       cout<<"Enter your choice and its Quantity : ";
       int cho; 
       cin>>cho;
        if(cho == 0)
       {
           return;
       }
       
       int quantity; 
       cin>>quantity;

       netbill["Pizza"].push_back(make_pair(vegp[cho].first , vegp[cho].second * quantity) );

       price+= vegp[cho].second * quantity;

    }

    void nonvegpizza(){
        
         cout<<"--------Non-Veg Pizza-------"<<endl;
       for(auto itp: nonvegp)
       {
           cout<<itp.first<<". "<<itp.second.first<<" --> "<<itp.second.second<<endl;
       }
       cout<<"Press 0 to exit"<<endl;
       cout<<"Enter your choice and its Quantity : ";
       int cho; cin>>cho;
        if(cho == 0)
       {
           return;
       }
       int quantity; cin>>quantity;
       netbill["Pizza"].push_back(make_pair(nonvegp[cho].first , nonvegp[cho].second * quantity) );
       price+= nonvegp[cho].second * quantity;
    }

    public:
    
   void display(){
        cout<<"Which one would you like to order? \n 1) Veg pizza\n 2) Non Veg pizza \n";
    int ch;
    cin>>ch;
    switch(ch)
    {
    case 1: vegpizza(); break;
    case 2: nonvegpizza(); break;
    default : return;
    }
    }
};

class Burgers{
   
    void vegburgers(){
       
       cout<<"--------Veg Burgers-------"<<endl;
       for(auto it: veg)
       {
           cout<<it.first<<". "<<it.second.first<<" --> "<<it.second.second<<endl;
       }
       cout<<"Press 0 to exit"<<endl;
       cout<<"Enter your choice and its Quantity : \n";
       int chh; cin>>chh;
        if(chh == 0)
       {
           return;
       }
       int quantity; 
       cin>>quantity;
       netbill["Burgers"].push_back(make_pair(veg[chh].first , veg[chh].second * quantity) );
       price+= veg[chh].second * quantity;

    }
    void nonvegburgers(){
        
         cout<<"--------Non-Veg Burgers-------"<<endl;
       for(auto it: nonveg)
       {
           cout<<it.first<<". "<<it.second.first<<" --> "<<it.second.second<<endl;
       }
       cout<<"Press 0 to exit"<<endl;
       cout<<"Enter your choice and its Quantity : ";
       int chh; cin>>chh;
        if(chh == 0)
       {
           return;
       }
       int quantity; cin>>quantity;
       netbill["Burgers"].push_back(make_pair(nonveg[chh].first , nonveg[chh].second * quantity) );
       price+= nonveg[chh].second * quantity;
    }

    public:
    
    void display(){
        cout<<"Which one would you like to have : \n 1) Veg Burger 2) Non veg Burger\n";
        int c; cin>>c;
        switch(c)
        {
            case 1: vegburgers(); break;
            case 2: nonvegburgers(); break;
            default : return;
        }
    }
};

class Beverages{
   
    void beveragetype(){
      
       cout<<"--------Beverages-------"<<endl;
       for(auto it: beverage)
       {
           cout<<it.first<<". "<<it.second.first<<" --> "<<it.second.second<<endl;
       }
       cout<<"Press 0 to exit"<<endl;
       cout<<"Enter your choice \n";
       int chh; cin>>chh;
        if(chh == 0)
       {
           return;
       }
       if (chh == 2)
       {
           for(auto it: softdrink){
               cout<<it.first<<" --> "<<it.second<<endl;
           }
           cout<<"Choose the one you want \n";
           int h; 
           cin>>h;
       }
       cout<<"Enter quantity \n";
       int quantity; cin>>quantity;
       netbill["Beverages"].push_back(make_pair(beverage[chh].first , beverage[chh].second * quantity) );
       price+= beverage[chh].second * quantity;

    }

    public:
    
    void display(){
        cout<<"Which one would you like to have : \n";
        beveragetype();
    }

};

class Desserts{
   
    void dessertstype(){
       cout<<"--------Desserts-------"<<endl;
       for(auto it:dessert)
       {
           cout<<it.first<<". "<<it.second.first<<" --> "<<it.second.second<<endl;
       }
       cout<<"Press 0 to exit"<<endl;
       cout<<"Enter your choice and its Quantity : ";
       int choi; cin>>choi;
       if(choi == 0)
       {
           return;
       }
       int quantity; cin>>quantity;
       netbill["Desserts"].push_back(make_pair(dessert[choi].first , dessert[choi].second * quantity) );
       price+= dessert[choi].second * quantity;

    }

    public:
    
    void display(){
        cout<<"Which one would you like to have : \n";
        dessertstype();
    }

};



class Sides{
   
    void sidestype(){
       cout<<"--------Sides And Others-------"<<endl;
       for(auto it:sides)
       {
           cout<<it.first<<". "<<it.second.first<<" --> "<<it.second.second<<endl;
       }
       cout<<"Press 0 to exit"<<endl;
       cout<<"Enter your choice and its Quantity : ";
       int choi; cin>>choi;
        if(choi == 0)
       {
           return;
       }
       int quantity; cin>>quantity;
       netbill["Sides and others"].push_back(make_pair(sides[choi].first, sides[choi].second * quantity) );
       price+= sides[choi].second * quantity;

    }

    public:
    
    void display(){
        cout<<"Which one would you like to have : \n";
        sidestype();
    }
};



class food: public Beverages, public Pizza, public Burgers, public Desserts, public Sides{

    public:
    food(){
    
       sides[1] = make_pair("Garlic breadsticks" ,99);
       sides[2] = make_pair("Cheesy Jalapeno dip" ,25);
       sides[3] = make_pair("White pasta italiano veg" ,135);
       sides[4] = make_pair("White pasta italiano non-veg" ,145);
       sides[5] = make_pair("Stuffed garlic breadsticks" ,145);
       sides[6] = make_pair("Taco mexicana non-veg" ,135);
       sides[7] = make_pair("Taco mexicana veg" ,118);
       sides[8] = make_pair("Chicken parcel" ,45);
       sides[9] = make_pair("Veg parcel" ,39);
       sides[10] = make_pair("Crunchy strips" ,59);
       sides[11] = make_pair("Crinkle fries" ,59);

       dessert[1] = make_pair("Choco lava" ,99);
       dessert[2] = make_pair("Butterscotch mousse cake" ,99);
       dessert[3] = make_pair("Donuts" ,50);
       dessert[4] = make_pair("Apple pie" ,100);
       dessert[5] = make_pair("Dutch truffle" ,75);
       dessert[6] = make_pair("Brownie fantasy" ,59);

       nonvegp[1] = make_pair("Pepper barbecue" ,400);
       nonvegp[2] = make_pair("Chicken sausage" ,500);
       nonvegp[3] = make_pair("Chicken golden delight" ,550);
       nonvegp[4] = make_pair("Non veg supreme" ,460);
       nonvegp[5] = make_pair("Chicken dominator" ,550);
       nonvegp[6] = make_pair("Pepper barbecue & onion" ,550);
       nonvegp[7] = make_pair("Chicken fiesta" ,350);
       nonvegp[8] = make_pair("Indi chicken tikka" ,530);

       vegp[1] = make_pair("Margharita" ,450);
       vegp[2] = make_pair("Double cheese Margharita" ,400);
       vegp[3] = make_pair("Farm house" ,350);
       vegp[4] = make_pair("Mexican green wave" ,420);
       vegp[5] = make_pair("Deluxe veggie" ,450);
       vegp[6] = make_pair("Veg extravaganza" ,450);
       vegp[7] = make_pair("Panner makhani" ,350);
       vegp[8] = make_pair("Indi tandoori panner" ,450);
       vegp[9] = make_pair("Peppy paneer" ,340);
       vegp[9] = make_pair("Cheese n corn" ,400);
  
       softdrink[1] = "Thumbs Up";
       softdrink[2] = "Mirinda";
       softdrink[3]= "Coke";
       softdrink[4] = "Fanta";
       softdrink[5] = "Limca";
       softdrink[5] = "Mountain Dew";
       softdrink[6] = "Sprite";

       beverage[1] = make_pair("Drinking Water" ,20);
       beverage[2] = make_pair("Cold Drink" ,40);
       beverage[3] = make_pair("Ice Tea" ,30);
       beverage[4] = make_pair("Cold Coffee" ,30);
       beverage[5] = make_pair("Virgin Mojito" ,55);

       nonveg[1] = make_pair("Crispy Chicken" ,40);
       nonveg[2] = make_pair("Chicken Chilli Cheese" ,50);
       nonveg[3] = make_pair("Chicken WHOOPER" ,55);
       nonveg[4] = make_pair("Chicken Grill" ,60);
       nonveg[5] = make_pair("King Egg" ,55);

       veg[1] = make_pair("Crispy Veg" ,30);
       veg[2] = make_pair("Veg Surprise" ,40);
       veg[3] = make_pair("Crispy Veg Supreme" ,50);
       veg[4] = make_pair("Paneer King" ,42);
       veg[5] = make_pair("Veg Chilly cheeze" ,45);


    cout<<"Kindly place your order "<<endl;
    cout<<"Choose what you would like to have\n";
    cout<<"1. Pizza\n2. Burger  \n3. Beverages\n4. Desserts \n5. Sides and others\n Press 0 to exit\n";
    int orr; cin>>orr;
    do{
        switch(orr)
    {
        case 1: Pizza::display(); break;
        case 2: Burgers::display(); break;
        case 3: Beverages::display(); break;
        case 4: Desserts::display(); break;
        case 5: Sides::display(); break;
        default: orr =0;
    }
    cout<<"Again, please choose what you would like to have\n";
    cout<<"1. Pizza\n2. Burger  \n3. Beverages\n4. Desserts \n5. Sides and others\n Press 0 to exit\n";
    cin>>orr;
   

   

    }while(orr != 0);
    }
};


void displaybill(){
    cout<<"\t---BILL--\n";
    for(auto it: netbill)
    {
        cout.width(15);
        cout<<it.first;
        cout<<endl;
        int turn =1;
        for(auto components: it.second)
        {
            cout<<turn++<<". "<<components.first<<" --> "<<components.second<<endl;
        }
    }
}


int main(){
    cout<<"\t\t---------WELCOME TO KMS FAST FOOD POINT---------\n";
    cout<<"Enter your name : ";
    string name; cin>>name;
    cout<<"\n Welcome "<<name<<" , I hope you might be able to satisfy your taste buds to the fullest. \n";
    food foo;
    displaybill();
    cout<<"Your total price is : "<<price<<endl;
    return 0;
}


//code fixing----> multiple storage
//presntable---> options, menu