
def merge_sort(array,start,mid,end):
	size_low = mid - start + 1
	size_end = end - mid
	array1 = [0]*(size_low)
	array2 = [0]*(size_end)

	i=0
	j=0
	
	while(i<size_low):
		array1[i] = array[start+i]
		i+=1

	while(j<size_end):
		array2[j] = array[mid+j+1]
		j+=1
	
	m=n=0
	k = start

	while(m<size_low and n<size_end):
		if(array1[m]<= array2[n]):
			array[k] = array1[m]
			k+=1
			m+=1

		else:
			array[k]= array2[n]
			k+=1
			n+=1


	while(m<size_low):
		array[k] = array1[m]
		k+=1
		m+=1

	while(n<size_end):
		array[k] = array2[n]
		k+=1
		n+=1


def merge_call(nums,start,end):
	if(start<end):
		mid_value = int((start + end)/2)
		merge_call(nums,start,mid_value)
		merge_call(nums,mid_value+1,end)
		merge_sort(nums,start,mid_value,end)



list = [100,2,-1,9,0,4]
size_list = len(list)
merge_call(list,0,size_list-1)
print(list)


		
	
	
			
			
			

		
		


   

	
