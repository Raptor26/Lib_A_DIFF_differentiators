/*
 * Lib_A_DIFF_differentiators.c
 *
 *  Created on: 2 февр. 2018 г.
 *      Author: m.isaev
 */



/******************************************************************************/
// 	Секция include: здесь подключается заголовочный файл к модулю
#include "Lib_A_DIFF_differentiators.h"
/******************************************************************************/


/******************************************************************************/
/*============================================================================*/
// 	Глобальные переменные
/*============================================================================*/


/*============================================================================*/
// 	Локальные переменные
/*============================================================================*/
/******************************************************************************/


/******************************************************************************/
// 	Секция прототипов локальных функций
/******************************************************************************/


/******************************************************************************/
// 	Секция описания функций (сначала глобальных, потом локальных)

/**
 * @brief	Функция выполняет дифференцирование методом 1-го порядка
 * @param[in,out]	*p_s:	Указатель на структуру дифференцирования методом
 * 							1-го порядка
 * @param[in]	value:	Новое значение переменной для дифференцирования
 * @return	Дифференцированное значение
 */
__DIFF_FPT__
DIFF_GetDifferent1(
	diff_differentiator_1_s *p_s,
	__DIFF_FPT__ value)
{
	//	Дифференцирование методом 1-го порядка;
	__DIFF_FPT__ diff =
		(value - p_s->preValue) / p_s->dT;

	//	Копирование текущего значения в переменную для хранения значения за
	//	шаг <t-1>;
	p_s->preValue = value;

	//	Возврат дифференцированного значения;
	return diff;
}

/**
 * @brief	Функция выполняет инициализацию структуры для выполнения
 *        	дифференцирования методом 1-го порядка
 * @param[out]	*p_s:	Указатель на структуру дифференцирования методом
 * 						1-го порядка
 * @param[in]	*pInit_s:	указатель на структуру, в которой содержатся
 * 							параметры для инициализации структуры
 * 							diff_differentiator_1_s
 * @return	diff_fnc_status_e:
 *			- DIFF_ERROR:	Если неверно задан один из параметров структуры
 *							regul_pid_init_struct_s
 *			- DIFF_SUCCESS:	Инициализация прошла успешно
 */
diff_fnc_status_e
DIFF_Init_Different1(
	diff_differentiator_1_s *p_s,
	diff_differentiation_1_init_struct_s *pInit_s)
{
	if (pInit_s->dT != (__DIFF_FPT__) 0.0)
	{
		p_s->dT = pInit_s->dT;
		p_s->initStatus = DIFF_SUCCESS;
	}
	else
	{
		p_s->initStatus = DIFF_ERROR;
	}

	return (p_s->initStatus);
}

/**
 * @brief	Функция инициализирует структуру параметрами по умолчанию
 * @param[in]	*pInit_s:	Указатель на структуру инициализации
 * @return	None
 */
void
DIFF_Different1_StructInit(
	diff_differentiation_1_init_struct_s *pInit_s)
{
	pInit_s->dT = (__DIFF_FPT__) 0.0;
}
/*============================================================================*/

/*============================================================================*/
/******************************************************************************/


////////////////////////////////////////////////////////////////////////////////
// 	END OF FILE
////////////////////////////////////////////////////////////////////////////////
