/*class node {
    private:
        string value;
        vector<node> * child;
        node * parent;
    public:
        node(string invalue){
            value = invalue;
        }
};*/
/*
SHELL
 node * root = new node("/");
    node * CURRENTDIRECTORY = root;
    string CURRENTDIR = "";

    cd:
    string COMMAND = path;
	    for(int i = 0; i < COMMAND.length();i++){
            //cout << COMMAND[i] << "+";
            if(COMMAND[i] != '/'){//BUILD A FOLDERNAME
                CURRENTDIR+=(COMMAND[i]);
            }
            else{//WE ARE DONE WITH OUR CURRENT NAME
                cout<<"FOLDER: " << CURRENTDIR << endl;
                node * NewFolder = new node();
                CURRENTDIRECTORY->child.push_back()
                CURRENTDIR = "";
            }
	    }*/
