#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void PrintBucket(unordered_map<string,string> mymap)
{
  for ( auto it = mymap.begin(); it != mymap.end(); ++it ) std::cout << " " << it->first << ":" << it->second;
  std::cout << std::endl;
  std::cout << "buckets contain:\n";
  for ( unsigned i = 0; i < mymap.bucket_count(); ++i) 
  {
      std::cout << "bucket #" << i << " contains:";
      for ( auto local_it = mymap.begin(i); local_it!= mymap.end(i); ++local_it )
          std::cout << " " << local_it->first << ":" << local_it->second;
      std::cout << std::endl;
  }
}
int main()
{
    std::unordered_map<std::string,std::string> imap;
    imap = {{"Australia","Canberra"},{"U.S.","Washington"},{"France","Paris"}};
    std::unordered_map<std::string,std::string> iimap({{"Australia","Canberra"},{"U.S.","Washington"},{"France","Paris"}});
    cout<<endl;
    PrintBucket(imap);cout<<endl;
    PrintBucket(iimap);
    return 0;
}
