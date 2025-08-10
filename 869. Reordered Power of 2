bool reorderedPowerOf2(int n) {
    for (int i = 0; i <= 30; i++) {
        bool flag = 1;
        int cur = (1 << i);
		int f1[10] = {0};
        int f2[10] = {0};
        int tmp = n;
        while (tmp) {
            f1[tmp % 10]++;
            tmp /= 10;
        }
        while (cur) {
            f2[cur % 10]++;
            cur /=10;
        }
        for (int j = 0; j < 10; j++) {
            if (f1[j] != f2[j]) flag = 0;
        }
		if (flag) return 1;
    }
    return 0;
}
