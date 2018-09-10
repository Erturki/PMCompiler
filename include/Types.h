/*
 * Types.h
 *
 *  Created on: Jul 30, 2018
 *      Author: AiTG145
 */

#ifndef TYPES_H_
#define TYPES_H_

typedef enum {
	INT_LITERAL,
	FLOAT_LITERAL,
	CHAR_LITERAL
} LITERAL_TYPE;

typedef enum {
	FUNC = 1,
	PARAM,
	VAR,
	POINTER,
	LABEL,
	TYPEDEF_TYPE
} SymbolType;

typedef enum {
	AUTO = 1,
	EXTERN,
	REGISTER,
	STATIC,
	TYPEDEF_STORAGE
} StorageClass;

typedef enum {
	VOID = 1,
	CHAR,
	SHORT,
	INT,
	LONG,
	FLOAT,
	DOUBLE,
	SIGNED,
	UNSIGNED,
	BOOL,
	STRUCT,
	UNION,
	ENUM,
	TYPEDEF
} TypeSpecifier;

typedef enum {
	CONST = 1,
	VOLATILE
} TypeQualifier;


#endif /* TYPES_H_ */
