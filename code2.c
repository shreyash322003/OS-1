#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// bubble Sort function to sort array in ascending order
// Parent will sort array in ascending manner
void bubbleSort_ascending(int array[], int size)
{
    for (int step = 0; step < size - 1; ++step)
    {
        for (int i = 0; i < size - step - 1; ++i)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

// bubble Sort function to sort array in descending order
// Parent will sort array in descending manner
void bubbleSort_descending(int array[], int size)
{
    for (int step = 0; step < size - 1; ++step)
    {
        for (int i = 0; i < size - step - 1; ++i)
        {
            if (array[i] < array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

// print function to print array by using parent process
void print_parent(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d (Process Id = %d with ppId = %d)\n", array[i], getpid(), getppid());
        sleep(1);
    }
}
// print function to print array by using child process
void print_child(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("	%d (Process Id = %d with ppId = %d)\n", array[i], getpid(), getppid());
        sleep(2);
    }
}

int main()
{
    int size; // taking size of array
    printf("Enter the number of elements : ");
    scanf("%d", &size);
    int a[size];
    printf("Enter array elements : \n");
    // taking array elements
    for (int i = 0; i < size; i++)
    {
        printf("a[%d] : ", i + 1);
        scanf("%d", &a[i]);
    }
    // calling fork system call
    int p = fork();
    // fork() will return p > 0 to parent
    if (p > 0)
    {
        bubbleSort_ascending(a, size);
        print_parent(a, size);
        // sleep(300);
        // wait(NULL);
        printf("parent terminating\n");
    }
    else if (p == 0)
    {
        // fork() will return p = 0 to child
        bubbleSort_descending(a, size);
        print_child(a, size);
        printf("child terminating\n");
    }
    else
    {
        // fork() will return p < 0 is child is not created
        printf("Child is not created");
    }
}
