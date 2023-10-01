void reverse(int l, int r, char* s){
    int d=r-l;
    for(int i=0; i<=d/2; i++){
        int tmp=s[l+i];
        s[l+i]=s[r-i];
        s[r-i]=tmp;
    }
}
char * reverseWords(char * s){
    int n=strlen(s);
    int prev=0;
    for(int i=0; i<n; i++){
        if (s[i]==' '){//All the words in s are separated by a single space.
            reverse(prev, i-1, s);
            prev=i+1;
        }
    }
    reverse(prev, n-1, s);
    return s;
}
