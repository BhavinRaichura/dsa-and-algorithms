## string::npos
    - It is a constant static member value with the highest possible value for an element of type size_t.
    - It actually means until the end of the string.
    - It is used as the value for a length parameter in the string’s member functions.
    - As a return value, it is usually used to indicate no matches
    ## Q) check if strings are rotations of each other or not

## next_permutation
    to find the next permutation of given string 
        next_permutation(str.begin(),str.end())
    it will change string to next permutation
        is_permutation(str1.begin(),str1.end(),str2.begin())
        prev_permutation(str.begin(),str.end())
