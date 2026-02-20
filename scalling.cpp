#include <glut.h>
// Fungsi untuk menggambar objek dengan scaling
void userdraw()
{
 glPushMatrix(); // Menyimpan matriks model-view saat ini
 // Translasi titik ke (300, 300)
 // glTranslatef(300.0f, 300.0f, 0.0f);
 // Melakukan scaling (2x lebih besar di sumbu X dan Y)
 glScalef(2.0f, 2.0f, 1.0f);
 glPointSize(10); // Mengatur ukuran titik (point size) menjadi 10 piksel
 glBegin(GL_POINTS); // Memulai menggambar bentuk titik
 glVertex2f(100, 100); // Menentukan koordinat titik asli (100, 100)
 glEnd(); // Mengakhiri proses menggambar bentuk
 glPopMatrix(); // Mengembalikan matriks model-view ke keadaan sebelumnya
}
// Fungsi untuk menampilkan gambar pada jendela
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT); // Membersihkan layar dengan warna latar belakang
 userdraw(); // Memanggil fungsi untuk menggambar
 glutSwapBuffers(); // Menukar buffer untuk menampilkan gambar di layar
}
// Fungsi utama program
int main(int argc, char **argv)
{
 glutInit(&argc, argv); // Inisialisasi GLUT
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Menggunakan mode tampilan double buffer dan warna RGB
 glutInitWindowPosition(100, 100); // Menentukan posisi jendela di layar (100, 100)
 glutInitWindowSize(640, 480); // Menentukan ukuran jendela (640x480 piksel)
 glutCreateWindow("Scaling pada Objek OpenGL"); // Memberikan judul pada jendela
 glClearColor(1.0, 0.0, 0.0, 0.0); // Mengatur warna latar belakang menjadi merah (format RGBA)
 gluOrtho2D(0., 640., 0., 480.); // Mengatur koordinat sistem proyeksi ortografis 2D
 glutIdleFunc(display); // Menentukan fungsi yang akan dijalankan saat idle
 glutDisplayFunc(display); // Menentukan fungsi yang akan dijalankan untuk menggambar
 glutMainLoop(); // Memulai loop utama GLUT (menunggu dan merespons event)
 return 0; // Mengembalikan nilai 0 untuk menandakan program selesai
}