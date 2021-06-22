//Find
			BYTE					accept;
			
///Add
#if defined(__BL_ADVANCED_DUEL__)
			std::uint8_t			uPVPFlag;
#endif

//Find
		void			SetAcceptToSelf(BYTE Accept);
		
///Add
#if defined(__BL_ADVANCED_DUEL__)
		void			SetDuelFlagToTarget(std::uint8_t uFlag);
		void			SetDuelFlagToSelf(std::uint8_t uFlag);

		std::uint8_t	GetDuelFlagFromTarget() const;
		std::uint8_t	GetDuelFlagFromSelf() const;
#endif