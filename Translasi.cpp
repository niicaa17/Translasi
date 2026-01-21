#include <stdlib.h> // Library standar C (untuk fungsi umum seperti exit, memory, dll)
#include <glut.h> // Library GLUT untuk membuat window dan mengontrol OpenGL
// Fungsi untuk menggambar objek
void userdraw (void)
{
glBegin(GL_LINE_LOOP); // Mulai menggambar garis tertutup (loop)
glColor3f(1.,1.,0.); // Mengatur warna merah (RGB: 1,0,0)
glVertex2f(50,50); // Titik pertama di koordinat (50,50)
glColor3f(0.,1.,1.); // Warna hijau
glVertex2f(300,50); // Titik kedua (300,50)
glColor3f(1.,1.,1.); // Warna biru
glVertex2f(300,300); // Titik ketiga (300,300)
glColor3f(1.,0.,1.); // Kembali ke warna merah
glVertex2f(50,300); // Titik keempat (50,300)
glEnd(); // Selesai menggambar objek
glFlush(); // Memaksa OpenGL menggambar segera
}
// Fungsi display: dipanggil setiap kali layar harus diperbarui
void display ()
{
glClear(GL_COLOR_BUFFER_BIT); // Membersihkan layar (buffer warna)
glTranslated(10,10,0); // Translasi objek: geser 10 unit ke kanan pada sumbu X
userdraw(); // Gambar objek yang sudah didefinisikan
glFlush(); // Tampilkan hasil gambar ke layar
}
// Fungsi timer untuk animasi
void timer (int value)
{
glutPostRedisplay(); // Menandai bahwa display harus digambar ulang
glutTimerFunc(100, timer, 0); // Timer dipanggil lagi setelah 100 ms (loop animasi)
}
// Fungsi utama program
void main (int argc, char **argv)
{
glutInit (&argc, argv); // Inisialisasi GLUT
glutInitDisplayMode (GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA); // Mode tampilan: kedalaman, buffer tunggal,warna RGBA
glutInitWindowPosition(100,100); // Posisi window di layar
glutInitWindowSize(640,480); // Ukuran window (lebar x tinggi)
glutCreateWindow("Translasi"); // Judul window
gluOrtho2D(0.,640.,0.,640.); // Mengatur proyeksi 2D: area koordinat (x:0-640, y:0-640)
glutDisplayFunc(display); // Daftarkan fungsi display
glutTimerFunc(5, timer, 1000); // Timer pertama dipanggil setelah 5 ms
glutMainLoop(); // Masuk ke loop utama GLUT (program berjalan terus)
}