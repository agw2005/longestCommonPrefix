#include <iostream>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string> strs)
{
    char placeholder;
    std::string result;
    int shortestStringIndex = 0;
    bool sameCharacter;
    for(int vectorIteration = 0 ; vectorIteration < (int)strs.size() ; vectorIteration++)
    {
        //0 1 2 ...
        if( (int)strs[shortestStringIndex].length() > (int)strs[vectorIteration].length() )
            {shortestStringIndex = vectorIteration;}
    }

    for(int shortestStringIteration = 0 ; shortestStringIteration < (int)strs[shortestStringIndex].size() ; shortestStringIteration++)
    {
        sameCharacter = true;
        for(int vectorIteration = 0 ; vectorIteration < (int)strs.size() ; vectorIteration++)
        {
            if(vectorIteration == 0)
            {
                placeholder = strs[vectorIteration][shortestStringIteration];
                continue;
            }

            else
            {
                if(strs[vectorIteration][shortestStringIteration] == placeholder)
                    {continue;}
                else
                {
                    sameCharacter = false;
                }
            }
        }
        if(sameCharacter){result += placeholder;}
        else{break;}
    }
    return result;
}

int main()
{
    std::vector<std::string> example  = {"cir","car"};
    std::cout<<longestCommonPrefix(example);
    //Expected output: "fl"
}