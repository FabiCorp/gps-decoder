# gps-decoder  

This was an assignment from university.  

We needed to destruct the incoming signal and find out which four satellites send a message.  
Further we needed to identify the message from each sattelite (0 or 1).  

We started by implementing a C++ variant with heavy std library objects.  
The following step was to convert it to a C variant with no external objects from librarys.  
The final step was the optimization of the C variant with different approches (inline functions, loop unrolling, compiler flag, etc.).
