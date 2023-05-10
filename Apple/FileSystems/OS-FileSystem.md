# Important terms:-
  * Inodes:- Inodes do not store actual data. Instead, they store the metadata where you can find the storage blocks of each file’s data.
  * Superblock:- The superblock abstraction contains information about the filesystem instance such as the block size, the root inode, filesystem size. It is present both on storage and in memory (for caching purposes).
  * The file abstraction contains information about an opened file such as the current file pointer. It only exists in memory.
  * Dentry:-  associates a name with an inode. It exists both on storage and in memory (for caching purposes).

# System Calls associated with fs/vnode:-
 * dup() :- https://man7.org/linux/man-pages/man2/dup.2.html
 * fget():- 
 * getdent() :- https://man7.org/linux/man-pages/man2/getdents.2.html
 * lseek() :- https://man7.org/linux/man-pages/man2/lseek.2.html
 * vnode() 
 * mount() :- https://man7.org/linux/man-pages/man2/mount.2.html
 * mmap():- https://man7.org/linux/man-pages/man2/mmap.2.html
 * fork() :- https://man7.org/linux/man-pages/man2/fork.2.html
 * * execve() :- https://man7.org/linux/man-pages/man2/execve.2.html


# Link:-
   * Virtual File System:- https://linux-kernel-labs.github.io/refs/heads/master/lectures/fs.html
   * Inode data structure man page:- https://man7.org/linux/man-pages/man7/inode.7.html
   * Difference between B and B+ tree:- https://stackoverflow.com/questions/870218/what-are-the-differences-between-b-trees-and-b-trees
   * Best fit/First fit algorithm:- https://www.cs.nott.ac.uk/~pszgxk/courses/g53ops/Memory%20Management/MM07-allocationstrategies.html#:~:text=Best%20fit%20is%20slower%20than,use%20the%20largest%20hole%20available.


