class Number {
    private:
        double d;
    public:
        Number(const double& = 0.0);
        ~Number();
        operator int();
        operator double();
};