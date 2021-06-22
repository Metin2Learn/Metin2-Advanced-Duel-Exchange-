//Find
		bool		GetAcceptStatus() { return m_bAccept; }
		
///Add
#if defined(__BL_ADVANCED_DUEL__)
		std::uint8_t GetAdvancedDuelFlag() const;
		long		 GetGold() const;
		std::vector<LPITEM> GetItemVector() const;
		void		 SetAdvancedDuelFlag(std::uint8_t uFlag);
#endif

//Find
		CGrid *		m_pGrid;
		
///Add
#if defined(__BL_ADVANCED_DUEL__)
		std::uint8_t uPVPFlag; // CAdvancedPVP - EFLAG
#endif