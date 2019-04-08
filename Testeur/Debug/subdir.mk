################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Journal_Testeur.cpp \
../Ouvrage_Testeur.cpp \
../Reference_Testeur.cpp 

OBJS += \
./Journal_Testeur.o \
./Ouvrage_Testeur.o \
./Reference_Testeur.o 

CPP_DEPS += \
./Journal_Testeur.d \
./Ouvrage_Testeur.d \
./Reference_Testeur.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++03 -I"/home/etudiant/Bureau/TP3_avecTesteur/source" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


