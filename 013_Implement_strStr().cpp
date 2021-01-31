class Solution {
public:
    /*
     * @param source: source string to be scanned.
     * @param target: target string containing the sequence of characters to match
     * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
     */
    int strStr(const char *source, const char *target) {
        if(source == nullptr || target == nullptr){
            return -1;
        }
        string s1 = source;
        string t1 = target;
        if ( s1.size()==0 && t1.size()==0){
            return 0;
        }
        
        for(unsigned i=0; i<(s1.size() - t1.size()+1); i++){
            bool foundMisMatch = false;
            for(unsigned j=0; j< t1.size(); j++){
                if(s1[i+j] != t1[j]){
                    foundMisMatch = true;
                    break;
                }
            }
            if(!foundMisMatch){
                return i;
            }
        }
            
        return -1;
    }
};