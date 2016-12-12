int g_fun(int x, int a) {
    return x+a;
}
 
int f_fun(char *s, int i, char c) {
    g_fun(i, 3);
    return 0;
}
 
int main() {
    int ret = f_fun("abc", 1, 'x');
    return 1;
}
