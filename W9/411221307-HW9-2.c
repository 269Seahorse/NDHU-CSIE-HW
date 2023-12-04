int main() {
  init();
  int *p = arr;
  printf("%d, %d", *(p + 4), *(p + 31));
  return 0;
}
