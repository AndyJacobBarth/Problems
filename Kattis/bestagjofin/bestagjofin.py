n = int(input())
name, fun_metric = input().split()
fun_metric = int(fun_metric)

best_metric = fun_metric
best_name = name

while n > 1:
    name, fun_metric = input().split()
    fun_metric = int(fun_metric)

    if fun_metric > best_metric:
        best_metric = fun_metric
        best_name = name
    n-= 1
print(best_name)