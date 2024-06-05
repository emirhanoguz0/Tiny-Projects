import random
import time

class Time:
    def wtime(self):
        starttime = time.time()
        print("Siralanmis liste:", Sort().quicksort(self))
        endtime = time.time()
        print(f"Programın çalisma süresi: {(endtime - starttime):.15f}")

class Sort:
    def quicksort(self, arr):
        if len(arr) <= 1:
            return arr
        else:
            pivot = arr[0] # pivot seçilir
            smallnums = [x for x in arr if x < pivot] # pivottan küçük sayılar bir listeye konur
            pivotnums = [x for x in arr if x == pivot] # pivotta eşit elemanlar bir listeye konur
            bignums = [x for x in arr if x > pivot] # pivottan büyük sayılar bir listeye konur
            return self.quicksort(smallnums) + pivotnums + self.quicksort(bignums) # büyük ve küçük listeler kendi içinde sıralanır

    def randomlist(rangenum):
        testlist = []
        for i in range(rangenum):
            testlist.append(random.randint(-32000,32000))
        return testlist

arr = []
manueloto = int(input("Liste elemanlarını rastgele oluşturmak için 1'e,\nElle girmek için 2'ye basınız.\n"))
rangenum = int(input("Liste kaç elemanlı olsun\n"))
if manueloto == 1:
    arr = Sort.randomlist(rangenum)
if manueloto == 2:
    for i in range(rangenum):
        arr.append(int(input("Eleman giriniz: ")))
Time.wtime(arr)