// calculate base^expo
ll binPow(ll base, ll expo) {
  ll res = 1;
  while (expo) {
    if (expo & 1) {
      res = res * base % mod;
    }
    expo /= 2;
    base = base * base % mod;
  }
  return res;
}
