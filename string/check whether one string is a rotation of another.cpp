//check whether one string is a rotation of another
/*
Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1? 
(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)
*/  
  
// method 1 : check 1st char of both string and then rotate one of them
  
bool rotationalS1S2(string s1, string s2){
    string s3=s1;
    if (s1.size()!=s2.size())
        return false;
    for (int i=0;i<s1.size();i++){
        if (s1[i]==s2[0]){
            s3=s1;
            rotate(s3.begin(),s3.begin()+i,s3.end());
        }
        if (s3==s2)
            return true;
    }
    return false;
}

// method 2:------ using string ::npos 

bool checkRotationalS1S2(string s1, string s2){
    if (s1.size()!=s2.size())
        return false;
    string strs1 = s1;
    strs1+=s1;

    return (strs1.find(s2)!=string::npos);
}
/*
What is string::npos:

    It is a constant static member value with the highest possible value for an element of type size_t.
    It actually means until the end of the string.
    It is used as the value for a length parameter in the string’s member functions.
    As a return value, it is usually used to indicate no matches.
    */
// https://www.geeksforgeeks.org/stringnpos-in-c-with-examples/


// method 3: queue approach
bool check_rotation(string s, string goal)
{
    if (s.size() != goal.size())
        return false;
    queue<char> q1;
    for (int i = 0; i < s.size(); i++) {
        q1.push(s[i]);
    }
    queue<char> q2;
    for (int i = 0; i < goal.size(); i++) {
        q2.push(goal[i]);
    }
    int k = goal.size();
    while (k--) {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1)
            return true;
    }
    return false;
}
