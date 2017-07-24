
class encryption{
    public:
        static std::string encrypt(std::string s){
            int i;
            int l = s.length();
            for(i = 0;i < l; i++){
                s[i] = s[i] + l;
            }
            return s;
        }

        static std::string decrypt(std::string s){
            int i;
            int l = s.length();
            for(i = 0;i < l; i++){
                s[i] = s[i] - l;
            }
            return s;
        }
};
