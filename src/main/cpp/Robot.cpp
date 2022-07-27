// Copyright (c) FIRST and other WPILib contributors.
// Software livre; você pode modificá-lo e/ou compartilhá-lo sob os termos de
// o arquivo de licença WPILib BSD no diretório raiz deste projeto.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit() {}

/**
* Esta função é chamada de cada pacote de robô, não importa o modo. Usar
 * isso para itens como diagnósticos que você deseja executar durante a desativação,
 * autônomo, teleoperado e teste.
 *
 * <p> Isso é executado após as funções periódicas específicas do modo, mas antes
 * Atualização integrada LiveWindow e SmartDashboard.
 */
void Robot::RobotPeriodic() {
  frc2::CommandScheduler::GetInstance().Run();
}

/**
* Esta função é chamada uma vez cada vez que o robô entra no modo Desativado. Você
 * pode usá-lo para redefinir qualquer informação do subsistema que você deseja limpar quando o
 * o robô está desabilitado.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * Este autônomo executa o comando autônomo selecionado pelo seu {@link
 * RobotContainer} classe.
 */

void Robot::AutonomousInit() {
  m_autonomousCommand = m_container.FinalAutonomousCommand();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {
}

void Robot::TeleopInit() {
  // Isso garante que o autônomo pare de funcionar quando
  // teleop começa a funcionar. Se você quer que o autônomo
  // continua até ser interrompido por outro comando, remove
  // esta linha ou comente-a.
  
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
}

/**
 * Esta função é chamada periodicamente durante o controle do operador.
 */

void Robot::TeleopPeriodic() {
  
}

/**
 * Esta função é chamada periodicamente durante o modo de teste.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
