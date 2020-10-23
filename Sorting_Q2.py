#function to shift all the zeros to the right
def shiftzeros(a,n):
    for i in range(n):
        if a[i]==0:
            m=i
            for j in range(m+1,n):
                temp=a[j]
                a[j]=a[m]
                a[m]=temp
                m+=1
            #this block is for the case when we swap two consecutive 0s to check at the same pos again
            if a[i]==0:
                m=i
                for j in range(m+1,n):
                    temp=a[j]
                    a[j]=a[m]
                    a[m]=temp
                    m+=1
            


a=[]
n=int(input("Enter the size of the array"))
print("Enter the array elements")
for i in range(n):
    ele =int(input())
    a.append(ele)
print("Array Elements before shifting are :")
print(a)
shiftzeros(a,n)
print("Array Elements after shifting are :")
print(a)
