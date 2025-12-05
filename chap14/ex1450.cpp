struct LongDouble
{
    LongDouble (double=0.0);
    operator double();
    operator float();


};

void calc(int);
void calc(LongDouble);

int main()
{
    LongDouble ldobj;
    int ex1 = ldobj;
    float ex2 = ldobj;

    double dval;
    calc(dval);


    return 0;
}