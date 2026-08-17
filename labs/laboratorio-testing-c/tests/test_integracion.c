#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

void test_compra_con_descuento(void){
    printf("\n[descuento carrito]\n");
    Carrito c;
    carrito_init(&c);
    Producto p1 = {"Pan", 200, 3};
    carrito_agregar(&c, p1);
    Producto p2 = {"Leche", 350, 2};
    carrito_agregar(&c, p2);
    ASSERT_IGUAL(1300, carrito_total(&c));
    int total = carrito_total(&c);
    ASSERT_IGUAL(1170, carrito_descuento(total, 10));
}

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

void test_agregar_hasta_llenar(void){
    printf("\n[carrito agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p1 = {"Pan", 200, 1};
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p1);
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
    ASSERT_IGUAL(0, carrito_agregar(&c, p1));
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
}

/* TODO: escribir test_agregar_hasta_llenar() */

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
