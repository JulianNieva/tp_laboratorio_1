/*
 * Menu.h
 *
 *  Created on: 2 jun. 2021
 *      Author: Julian
 */

#ifndef MENU_H_
#define MENU_H_

/**
 * @fn int MenuPrincipal(void)
 * @brief Muestro el menu principal al usuario
 *
 * @return Devuelvo la opcion seleccionada
 */
int MenuPrincipal(void);

/**
 * @fn int SubMenuModificar(void)
 * @brief Muestro un sub menu de Modificar
 *
 * @return Devuelvo la opcion seleccionada
 */
int SubMenuModificar(void);

/**
 * @fn int SubMenuCriterioOrdenamiento(void)
 * @brief Muestro los criterios de ordenamiento al usuario en un menu
 *
 * @return Devuelvo la opcion seleccionada
 */
int SubMenuCriterioOrdenamiento(void);

#endif /* MENU_H_ */
