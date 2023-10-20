// All the rights reserved.


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates=true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}
void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false,CursorHit);
	if (!CursorHit.bBlockingHit) return;
    LastActor=ThisActor;
	ThisActor=Cast<IEnemyInterface>(CursorHit.GetActor());

	if(LastActor == nullptr)
	{
		if(ThisActor != nullptr)
		{
			//Case B
			ThisActor->HighlightActor();
		}
		else
		{
			{
				//Case A, both are null, do nothing 
			}
		}
	}else  //LastActor is valid
	{
		if(ThisActor == nullptr)
		{
			//Case C
			LastActor->UnHighlightActor();
		}
		else //both actors are valid
		{
			if(LastActor != ThisActor)
			{
				//Case D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				//Case E, do nothing
			}
		}
	}
	
}
	
void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	auto* EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(EnhancedInputSubsystem)
	{
		EnhancedInputSubsystem->AddMappingContext(AuraContext, 0);
	}
    
	
 
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
 
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator YawRotation(0.0f, GetControlRotation().Yaw, 0.0f);
 
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
 
	APawn* ControlledPawn = GetPawn();
	if(!IsValid(ControlledPawn))
	{
		return;
	}
 
	ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
	ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
}

