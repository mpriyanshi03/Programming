int main(){
    string s;
    //vector<string> array={"purp","p","le","ur","purpl"};
    //vector<string> array={"abcd","ab","abc","def","cd"};
    //vector<string> array={"a","p","ent","enter","ot","o","t"};
    //vector<string> array={"bo","rd","ate","t","ska","sk","boar"};
    vector<string> array={"e","ee","eee","eeeeee"};
    cin>>s;
    int count=0;
    unordered_map<string, int> map;
    cout<<countconstruct(s,array,count,map)<<endl;
    //cout<<countconstruct(s,array,count)<<endl;
    