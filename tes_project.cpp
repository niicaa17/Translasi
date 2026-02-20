#include <GL/glut.h>
#include <cmath>   // WAJIB untuk sin() dan cos()

// ================================
// FUNGSI GAMBAR BALOK (TINGKAT CANDI)
// ================================
void drawBlock(float x, float y, float scaleX, float scaleY) {
    glPushMatrix();

    glTranslatef(x, y, 0.0f);        // TRANSLASI
    glScalef(scaleX, scaleY, 1.0f);  // SCALING

    glBegin(GL_QUADS);
        glVertex2f(-20, 0);
        glVertex2f( 20, 0);
        glVertex2f( 20, 10);
        glVertex2f(-20, 10);
    glEnd();

    glPopMatrix();
}

// ================================
// FUNGSI GAMBAR STUPA (LINGKARAN)
// ================================
void drawStupa(float x, float y, float radius) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f);
        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.14159f / 180.0f;
            glVertex2f(
                std::cos(angle) * radius,
                std::sin(angle) * radius
            );
        }
    glEnd();

    glPopMatrix();
}

// ================================
// DISPLAY
// ================================
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Warna candi (abu-abu batu)
    glColor3f(0.5f, 0.5f, 0.5f);

    // Tingkat candi (bawah ke atas)
    drawBlock(0, -100, 3.5, 1.3);
    drawBlock(0, -80,  3.0, 1.2);
    drawBlock(0, -60,  2.6, 1.1);
    drawBlock(0, -40,  2.2, 1.0);
    drawBlock(0, -20,  1.8, 0.9);
    drawBlock(0,   0,  1.4, 0.8);
    drawBlock(0,  20,  1.0, 0.7);

    // Stupa utama
    glColor3f(0.3f, 0.3f, 0.3f);
    drawStupa(0, 40, 8);

    glFlush();
}

// ================================
// INISIALISASI
// ================================
void init() {
    glClearColor(0.9f, 0.9f, 1.0f, 1.0f); // Background langit
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-150, 150, -150, 150);     // Tampilan 2D
}

// ================================
// MAIN
// ================================
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Candi Borobudur - Translasi & Scaling");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
