import java.util.concurrent.Semaphore;

public class ReaderWriter {

    static int readcount=0;

    static Semaphore S=new Semaphore(1);

    static Semaphore wrt=new Semaphore(1);

    

    static class Reader implements Runnable{

        public void run(){

            try{

                S.acquire();

                readcount++;

                if(readcount==1)

                    wrt.acquire();

                S.release();

                System.out.println(Thread.currentThread().getName()+" Reading");

                Thread.sleep(500);

                System.out.println(Thread.currentThread().getName()+" Still Readding");

                S.acquire();

                readcount--;

                if(readcount==0)

                        wrt.release();

                S.release();

            }

            catch(Exception e){

                System.out.println(e);

            }

        }

    }   

        static class Writer implements Runnable{

            public void run(){

                try{

                    wrt.acquire();

                    System.out.println(Thread.currentThread().getName()+" Writing");

                    Thread.sleep(500);

                    System.out.println(Thread.currentThread().getName()+" Still Writing");

                    wrt.release();

                }

                catch(Exception e){

                    System.out.println(e);

                }

            }

        }



    public static void main(String[] args) {

        Reader r=new Reader();

        Writer w=new Writer();

        Thread t1=new Thread(r);

        Thread t2=new Thread(r);

        Thread t3=new Thread(w);

        t1.start();

        t1.setName("Reader 1 ");

        t2.start();

        t1.setName("Reader 2 ");

        t3.start();

        t3.setName("Writer");

    }

    

}