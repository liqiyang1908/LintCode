class Solution {
public:

    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */

    int strStr(string &source, string &target) {
        //获取两个字符串的长度
        int sourceLen = source.size();
        int targetLen = target.size();

        //注意特判，若target长度为0则答案为0
        if(targetLen == 0){
            return 0;
        }

        //若target长度大于source，则不可能匹配
        if(targetLen > sourceLen){
            return -1;
        }

        for(int i=0; i < sourceLen-targetLen+1; i++){
            //k表示比对时source中所指向的字符
            int k = i;
            for(int j = 0; j < targetLen; j++){
                if(source[k] == target[j]){
                    //最后一个字符匹配完成，输出答案
                    if(j == targetLen - 1){
                        return i;
                    }
                    k++;
                }
                //其中一个字符无法匹配，直接退出做下一次循环
                else{
                    break;
                }
            }
        }
        return -1;
    }
};
