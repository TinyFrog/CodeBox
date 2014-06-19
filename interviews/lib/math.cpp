long factorial(int m) {
    long factorial = 1;
    for (int i =m; i>0; i--) {
        factorial *= i;
    }
    return factorial;
}

// A better version here: http://stackoverflow.com/a/1838732/677596
long calculate_combination (int m, int n) {
    if (m == 0) {
        return 1;
    }

    long numerator = 1;
    for (int k = m; k>0; k--) {
        numerator *= n-k+1;
    }

    return numerator / factorial(m);
}
