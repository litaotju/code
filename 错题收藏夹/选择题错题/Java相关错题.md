1. synchronized 关键字和线程锁
如下代码肯定是 线程2先使出，然后线程1输出。并不会出现死锁现象。

```java
    public class TestSynchronized {

        public static void main(String[] args) {
            Object object = new Object();
            Thread thread = new Thread( new Runnable(){
                public void run(){
                    synchronized(object){
                        try {
                            object.wait();
                            System.out.println("Output from thread1");
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            });
            thread.start();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            new Thread(new Runnable(){
                public void run(){
                    synchronized(object){
                        object.notifyAll();
                        System.out.println("Output from thread2");
                    }
                }
            }).start();
        }

    }
```

