int accumulate(int n)
{
    static int total { 0 };
    total += n;

    return total;
}
